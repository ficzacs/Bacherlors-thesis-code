#include "mainwindow.h"
#include "load_mode.h"
#include "simulation_mode.h"
#include "ui_mainwindow.h"
#include "tutorial.h"
#include <QRandomGenerator>
#include <QGridLayout>
#include <QIntValidator>
#include <QThread>
#include <QSet>
#include <QQueue>
#include <QMessageBox>
#include <QStack>
#include <QVector>
#include <queue>
#include <vector>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), simMode(nullptr), loadMode(nullptr)
{
    ui->setupUi(this);
    generateButtons();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete simMode;
    delete loadMode;
}

void::MainWindow::initialize_buttons(){
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            gridLayout->setColumnStretch(j, 1);
            QPushButton *button = new QPushButton(this);
            button->setObjectName(QString("button_%1_%2").arg(i).arg(j));
            button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
            gridLayout->addWidget(button, i, j);
            connect(button, &QPushButton::clicked, this, &MainWindow::switch_buttons);
        }
    }

    start_x = QRandomGenerator::global()->bounded(20);
    start_y = QRandomGenerator::global()->bounded(20);
    finish_x = QRandomGenerator::global()->bounded(20);
    finish_y = QRandomGenerator::global()->bounded(20);

    QPushButton *startButton = qobject_cast<QPushButton*>(gridLayout->itemAtPosition(start_x, start_y)->widget());
    QPushButton *finishButton = qobject_cast<QPushButton*>(gridLayout->itemAtPosition(finish_x, finish_y)->widget());

    startButton->setStyleSheet("background-color: green");
    finishButton->setStyleSheet("background-color: red");
}

void MainWindow::generateButtons(){
    gridLayout = qobject_cast<QGridLayout*>(ui->buttons_layout);
    initialize_buttons();
}

void MainWindow::restart_buttons(){
    if (gridLayout != nullptr) {
        while (QLayoutItem *item = gridLayout->takeAt(0)) {
            if (item->widget()) {
                delete item->widget();
            }
            delete item;
        }
    }
}


void MainWindow::on_restart_button_clicked()
{
    restart_buttons();
    initialize_buttons();
}

void MainWindow::switch_buttons(){
    QPushButton *clickedButton = qobject_cast<QPushButton*>(sender());

    if (clickedButton) {
        if (clickedButton->styleSheet() != "background-color: black; color: white;") {
            clickedButton->setStyleSheet("background-color: black; color: white;");
        } else {
            clickedButton->setStyleSheet("");
        }
    }
    if(!is_map_valid()){
        QMessageBox::warning(this, "Warning", "The finish is now unreachable.");
        return;
    }
}

void MainWindow::load_map(int map[20][20]){
    restart_buttons();

    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            gridLayout->setColumnStretch(j, 1);
            QPushButton *button = new QPushButton(this);
            button->setObjectName(QString("button_%1_%2").arg(i).arg(j));
            button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
            gridLayout->addWidget(button, i, j);
            connect(button, &QPushButton::clicked, this, &MainWindow::switch_buttons);
        }
    }

    for(int i = 0; i < 20; i++){
        for(int j = 0; j < 20; j++){
            QPushButton *tmp = qobject_cast<QPushButton*>(gridLayout->itemAtPosition(i, j)->widget());
            if(map[i][j] == 1){
                tmp->setStyleSheet("background-color: black; color: white;");
            } else if(map[i][j] == 2){
                tmp->setStyleSheet("background-color: green");
                start_x = i;
                start_y = j;
            } else if(map[i][j] == 3){
                tmp->setStyleSheet("background-color: red");
                finish_x = i;
                finish_y = j;
            }
        }
    }
}

void MainWindow::on_exit_button_clicked()
{
    QApplication::closeAllWindows();
}

void MainWindow::generate_obstacle_buttons(int obstacles){
    QVector<QPair<int, int>> available_positions;

    for (int x = 0; x < 20; x++) {
        for (int y = 0; y < 20; y++) {
            if ((x == start_x && y == start_y) || (x == finish_x && y == finish_y))
                continue;

            QPushButton *button = qobject_cast<QPushButton*>(gridLayout->itemAtPosition(x, y)->widget());
            if (button && !button->styleSheet().contains("background-color: black")) {
                available_positions.append({x, y});
            }
        }
    }

    if (obstacles > available_positions.size()) {
        obstacles = available_positions.size();
    }

    for (int i = 0; i < obstacles; i++) {
        int rand_index = QRandomGenerator::global()->bounded(available_positions.size());
        int obstacle_x = available_positions[rand_index].first;
        int obstacle_y = available_positions[rand_index].second;

        QPushButton *obstacleButton = qobject_cast<QPushButton*>(gridLayout->itemAtPosition(obstacle_x, obstacle_y)->widget());
        if (obstacleButton) {
            obstacleButton->setStyleSheet("background-color: black; color: white;");
        }
        available_positions.removeAt(rand_index);
    }
}

void MainWindow::on_Obstacle_generate_button_clicked()
{
    int obstacle_num = ui->obstacle_input_data->value();
    generate_obstacle_buttons(obstacle_num);
}

bool MainWindow::is_map_valid(){
    QVector<QPair<int, int>> directions = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    QQueue<QPair<int, int>> queue;
    QVector<QVector<bool>> visited(400, QVector<bool>(400, false));

    queue.enqueue({start_x, start_y});
    visited[start_x][start_y] = true;

    while (!queue.isEmpty()) {
        auto [curr_x, curr_y] = queue.dequeue();

        if (curr_x == finish_x && curr_y == finish_y) {
            return true;
        }

        for (const auto& [dx, dy] : directions) {
            int new_x = curr_x + dx;
            int new_y = curr_y + dy;

            if (new_x >= 0 && new_x < 20 && new_y >= 0 && new_y < 20 && !visited[new_x][new_y]) {
                QPushButton* neighborButton = qobject_cast<QPushButton*>(gridLayout->itemAtPosition(new_x, new_y)->widget());

                if (neighborButton && neighborButton->styleSheet() != "background-color: black; color: white;") {
                    queue.enqueue({new_x, new_y});
                    visited[new_x][new_y] = true;
                }
            }
        }
    }
    return false;
}

void MainWindow::explore_randomwalk(int& explored, int& steps, bool delay) {
    QVector<QPair<int, int>> directions = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    int curr_x = start_x;
    int curr_y = start_y;
    QPushButton *currentButton = nullptr;

    QSet<QPair<int, int>> visitedTiles;
    visitedTiles.insert({curr_x, curr_y});

    while (curr_x != finish_x || curr_y != finish_y) {
        int randomDirection = QRandomGenerator::global()->bounded(4);
        int new_x = curr_x + directions[randomDirection].first;
        int new_y = curr_y + directions[randomDirection].second;

        if (new_x >= 0 && new_x < 20 && new_y >= 0 && new_y < 20) {
            QPushButton *nextButton = qobject_cast<QPushButton*>(gridLayout->itemAtPosition(new_x, new_y)->widget());
            steps++;

            if (nextButton->styleSheet() != "background-color: black; color: white;") {
                if (!visitedTiles.contains({new_x, new_y})) {
                    explored++;
                    visitedTiles.insert({new_x, new_y});
                }

                if (currentButton) {
                    currentButton->setStyleSheet("background-color: yellow; color: black;");
                }

                curr_x = new_x;
                curr_y = new_y;

                nextButton->setStyleSheet("background-color: blue; color: white;");
                currentButton = nextButton;

                if(delay){
                QCoreApplication::processEvents();
                QThread::msleep(ui->Delay_input_data->value());
                }
            }
        }
    }

    QPushButton *startButton = qobject_cast<QPushButton*>(gridLayout->itemAtPosition(start_x, start_y)->widget());
    QPushButton *finishButton = qobject_cast<QPushButton*>(gridLayout->itemAtPosition(finish_x, finish_y)->widget());
    startButton->setStyleSheet("background-color: green");
    finishButton->setStyleSheet("background-color: red");
}

struct Node {
    int x;
    int y;
    int h;

    Node(int x, int y, int h) : x(x), y(y), h(h) {}
};

int heuristic(int x, int y, int finish_x, int finish_y) {
    return abs(x - finish_x) + abs(y - finish_y);
}

bool nodeLessThan(const Node& a, const Node& b) {
    return a.h < b.h;
}

void MainWindow::explore_greedy_bfs(int& explored, int& steps, bool delay){
    QVector<QPair<int, int>> directions = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    QVector<QVector<bool>> visited(400, QVector<bool>(400, false));

    QList<Node> openList;
    openList.append(Node(start_x, start_y, heuristic(start_x, start_y, finish_x, finish_y)));
    visited[start_x][start_y] = true;

    QPushButton* currentButton = nullptr;

    while (!openList.isEmpty()) {
        std::sort(openList.begin(), openList.end(), nodeLessThan);
        Node current = openList.takeFirst();

        int curr_x = current.x;
        int curr_y = current.y;

        QPushButton* button = qobject_cast<QPushButton*>(gridLayout->itemAtPosition(curr_x, curr_y)->widget());
        if (button && button->styleSheet() != "background-color: black; color: white;") {
            if (currentButton) {
                currentButton->setStyleSheet("background-color: yellow; color: black;");
                explored++;
            }

            button->setStyleSheet("background-color: blue; color: white;");
            currentButton = button;
            steps++;

            if(delay){
                QCoreApplication::processEvents();
                QThread::msleep(ui->Delay_input_data->value());
            }
        }

        if (curr_x == finish_x && curr_y == finish_y) {
            break;
        }

        for (const auto& [dx, dy] : directions) {
            int new_x = curr_x + dx;
            int new_y = curr_y + dy;

            if (new_x >= 0 && new_x < 20 && new_y >= 0 && new_y < 20 && !visited[new_x][new_y]) {
                QPushButton* neighborButton = qobject_cast<QPushButton*>(gridLayout->itemAtPosition(new_x, new_y)->widget());
                if (neighborButton && neighborButton->styleSheet() != "background-color: black; color: white;") {
                    openList.append(Node(new_x, new_y, heuristic(new_x, new_y, finish_x, finish_y)));
                    visited[new_x][new_y] = true;
                }
            }
        }
    }

    QPushButton* startButton = qobject_cast<QPushButton*>(gridLayout->itemAtPosition(start_x, start_y)->widget());
    QPushButton* finishButton = qobject_cast<QPushButton*>(gridLayout->itemAtPosition(finish_x, finish_y)->widget());

    startButton->setStyleSheet("background-color: green");
    finishButton->setStyleSheet("background-color: red");
}


void MainWindow::explore_dfs(int& explored, int& steps, bool delay){
    QVector<QPair<int, int>> directions = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    QStack<QPair<int, int>> stack;
    QVector<QVector<bool>> visited(400, QVector<bool>(400, false));

    stack.push({start_x, start_y});
    visited[start_x][start_y] = true;

    QPushButton* currentButton = nullptr;

    while (!stack.isEmpty()) {
        auto [curr_x, curr_y] = stack.pop();

        QPushButton* button = qobject_cast<QPushButton*>(gridLayout->itemAtPosition(curr_x, curr_y)->widget());
        if (button && button->styleSheet() != "background-color: black; color: white;") {
            if (currentButton) {
                currentButton->setStyleSheet("background-color: yellow; color: black;");
                explored++;
            }

            button->setStyleSheet("background-color: blue; color: white;");
            currentButton = button;
            steps++;

            if(delay){
            QCoreApplication::processEvents();
            QThread::msleep(ui->Delay_input_data->value());
            }
        }

        if (curr_x == finish_x && curr_y == finish_y) {
            break;
        }

        for (const auto& [dx, dy] : directions) {
            int new_x = curr_x + dx;
            int new_y = curr_y + dy;

            if (new_x >= 0 && new_x < 20 && new_y >= 0 && new_y < 20 && !visited[new_x][new_y]) {
                QPushButton* neighborButton = qobject_cast<QPushButton*>(gridLayout->itemAtPosition(new_x, new_y)->widget());

                if (neighborButton && neighborButton->styleSheet() != "background-color: black; color: white;") {
                    stack.push({new_x, new_y});
                    visited[new_x][new_y] = true;
                }
            }
        }
    }

    QPushButton* startButton = qobject_cast<QPushButton*>(gridLayout->itemAtPosition(start_x, start_y)->widget());
    QPushButton* finishButton = qobject_cast<QPushButton*>(gridLayout->itemAtPosition(finish_x, finish_y)->widget());

    startButton->setStyleSheet("background-color: green");
    finishButton->setStyleSheet("background-color: red");
}

void MainWindow::explore_bfs(int& explored, int& steps, bool delay){
    QVector<QPair<int, int>> directions = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    QQueue<QPair<int, int>> queue;
    QVector<QVector<bool>> visited(400, QVector<bool>(400, false));

    queue.enqueue({start_x, start_y});
    visited[start_x][start_y] = true;

    QPushButton* currentButton = nullptr;

    while (!queue.isEmpty()) {
        auto [curr_x, curr_y] = queue.dequeue();

        QPushButton* button = qobject_cast<QPushButton*>(gridLayout->itemAtPosition(curr_x, curr_y)->widget());
        if (button && button->styleSheet() != "background-color: black; color: white;") {
            if (currentButton) {
                currentButton->setStyleSheet("background-color: yellow; color: black;");
                explored++;
            }

            button->setStyleSheet("background-color: blue; color: white;");
            currentButton = button;
            steps++;

            if(delay){
                QCoreApplication::processEvents();
                QThread::msleep(ui->Delay_input_data->value());
            }
        }

        if (curr_x == finish_x && curr_y == finish_y) {
            break;
        }

        for (const auto& [dx, dy] : directions) {
            int new_x = curr_x + dx;
            int new_y = curr_y + dy;

            if (new_x >= 0 && new_x < 20 && new_y >= 0 && new_y < 20 && !visited[new_x][new_y]) {
                QPushButton* neighborButton = qobject_cast<QPushButton*>(gridLayout->itemAtPosition(new_x, new_y)->widget());

                if (neighborButton && neighborButton->styleSheet() != "background-color: black; color: white;") {
                    queue.enqueue({new_x, new_y});
                    visited[new_x][new_y] = true;
                }
            }
        }
    }

    QPushButton* startButton = qobject_cast<QPushButton*>(gridLayout->itemAtPosition(start_x, start_y)->widget());
    QPushButton* finishButton = qobject_cast<QPushButton*>(gridLayout->itemAtPosition(finish_x, finish_y)->widget());

    startButton->setStyleSheet("background-color: green");
    finishButton->setStyleSheet("background-color: red");
}


void MainWindow::shortest_path_bfs(int& pathLength){
    QVector<QPair<int,int>> directions = {{-1,0},{0,-1},{1,0},{0,1}};

    QQueue<QPair<int, int>> queue;
    QMap<QPair<int, int>, QPair<int, int>> parent;
    QSet<QPair<int, int>> visited;

    queue.enqueue({start_x, start_y});
    visited.insert({start_x, start_y});
    parent[{start_x, start_y}] = {-1, -1};

    bool pathFound = false;

    while (!queue.empty() && !pathFound) {
        auto [x, y] = queue.front();
        queue.dequeue();

        for (const auto& dir : directions) {
            int new_x = x + dir.first;
            int new_y = y + dir.second;

            if (new_x >= 0 && new_x < 20 && new_y >= 0 && new_y < 20 && visited.find({new_x, new_y}) == visited.end()) {
                QPushButton *button = qobject_cast<QPushButton*>(gridLayout->itemAtPosition(new_x, new_y)->widget());

                if (button && (button->styleSheet() == "background-color: yellow; color: black;" || button->styleSheet() == "background-color: red")) {
                    queue.enqueue({new_x, new_y});
                    visited.insert({new_x, new_y});
                    parent[{new_x, new_y}] = {x, y};

                    if (new_x == finish_x && new_y == finish_y) {
                        pathFound = true;
                        break;
                    }
                }
            }
        }
        if (pathFound) {
            QPair<int, int> step = {finish_x, finish_y};
            while (step != qMakePair(-1, -1)) {
                int x = step.first;
                int y = step.second;

                if (step != qMakePair(start_x, start_y) && step != qMakePair(finish_x, finish_y)) {
                    QPushButton *button = qobject_cast<QPushButton*>(gridLayout->itemAtPosition(x, y)->widget());
                    if (button) {
                        button->setStyleSheet("background-color: purple; color: black;");
                        pathLength++;
                    }
                }

                step = parent[step];
            }
        }
    }

}

void MainWindow::shortest_path_dfs(int& pathLength) {
    QVector<QPair<int,int>> directions = {{-1,0},{0,-1},{1,0},{0,1}};

    QStack<QPair<int, int>> stack;
    QMap<QPair<int, int>, QPair<int, int>> parent;
    QSet<QPair<int, int>> visited;

    stack.push({start_x, start_y});
    visited.insert({start_x, start_y});
    parent[{start_x, start_y}] = {-1, -1};

    bool pathFound = false;

    while (!stack.empty() && !pathFound) {
        auto [x, y] = stack.top();
        stack.pop();

        for (const auto& dir : directions) {
            int new_x = x + dir.first;
            int new_y = y + dir.second;

            if (new_x >= 0 && new_x < 20 && new_y >= 0 && new_y < 20 && visited.find({new_x, new_y}) == visited.end()) {
                QPushButton *button = qobject_cast<QPushButton*>(gridLayout->itemAtPosition(new_x, new_y)->widget());

                if (button && (button->styleSheet() == "background-color: yellow; color: black;" || button->styleSheet() == "background-color: red")) {
                    stack.push({new_x, new_y});
                    visited.insert({new_x, new_y});
                    parent[{new_x, new_y}] = {x, y};

                    if (new_x == finish_x && new_y == finish_y) {
                        pathFound = true;
                        break;
                    }
                }
            }
        }
        if (pathFound) {
            QPair<int, int> step = {finish_x, finish_y};
            while (step != qMakePair(-1, -1)) {
                int x = step.first;
                int y = step.second;

                if (step != qMakePair(start_x, start_y) && step != qMakePair(finish_x, finish_y)) {
                    QPushButton *button = qobject_cast<QPushButton*>(gridLayout->itemAtPosition(x, y)->widget());
                    if (button) {
                        button->setStyleSheet("background-color: purple; color: black;");
                        pathLength++;
                    }
                }

                step = parent[step];
            }
        }
    }
}

struct AStarNode {
    int x, y;
    int g;
    int h;

    AStarNode(int x, int y, int g, int h) : x(x), y(y), g(g), h(h) {}

    int f() const { return g + h; }
};

bool aStarLessThan(const AStarNode& a, const AStarNode& b) {
    return a.f() < b.f();
}

struct CompareAStarNode {
    bool operator()(const AStarNode& a, const AStarNode& b) const {
        return a.f() > b.f();
    }
};

void MainWindow::explore_A_star(int& pathLength, int& explored, bool delay) {
    QVector<QPair<int, int>> directions = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    QMap<QPair<int, int>, QPair<int, int>> parent;
    QMap<QPair<int, int>, int> gScore;
    QSet<QPair<int, int>> closedSet;

    std::priority_queue<AStarNode, std::vector<AStarNode>, CompareAStarNode> openList;

    QPair<int, int> start = {start_x, start_y};
    QPair<int, int> goal = {finish_x, finish_y};

    gScore[start] = 0;
    parent[start] = {-1, -1};

    openList.push(AStarNode(start_x, start_y, 0, heuristic(start_x, start_y, finish_x, finish_y)));

    while (!openList.empty()) {
        AStarNode current = openList.top();
        openList.pop();
        QPair<int, int> currPos = {current.x, current.y};

        if (closedSet.contains(currPos)) continue;
        closedSet.insert(currPos);
        explored++;

        QPushButton* button = qobject_cast<QPushButton*>(gridLayout->itemAtPosition(current.x, current.y)->widget());
        if (button && button->styleSheet() != "background-color: black; color: white;") {
            if (!(current.x == start_x && current.y == start_y) && !(current.x == finish_x && current.y == finish_y))
                button->setStyleSheet("background-color: yellow; color: white;");

            if (delay) {
                QCoreApplication::processEvents();
                QThread::msleep(ui->Delay_input_data->value());
            }
        }

        if (currPos == goal) {
            QPair<int, int> step = currPos;
            while (step != QPair<int, int>(-1, -1)) {
                if (step != start && step != goal) {
                    QPushButton* stepButton = qobject_cast<QPushButton*>(gridLayout->itemAtPosition(step.first, step.second)->widget());
                    if (stepButton)
                        stepButton->setStyleSheet("background-color: purple; color: black;");
                    pathLength++;
                }
                step = parent.value(step, {-1, -1});
            }
            break;
        }

        for (const auto& [dx, dy] : directions) {
            int nx = current.x + dx;
            int ny = current.y + dy;
            QPair<int, int> neighbor = {nx, ny};

            if (nx >= 0 && nx < 20 && ny >= 0 && ny < 20 && !closedSet.contains(neighbor)) {
                QPushButton* neighborButton = qobject_cast<QPushButton*>(gridLayout->itemAtPosition(nx, ny)->widget());

                if (neighborButton && neighborButton->styleSheet() != "background-color: black; color: white;") {
                    int tentative_g = gScore[currPos] + 1;

                    if (!gScore.contains(neighbor) || tentative_g < gScore[neighbor]) {
                        gScore[neighbor] = tentative_g;
                        int h = heuristic(nx, ny, finish_x, finish_y);
                        openList.push(AStarNode(nx, ny, tentative_g, h));
                        parent[neighbor] = currPos;
                    }
                }
            }
        }
    }

    QPushButton* startButton = qobject_cast<QPushButton*>(gridLayout->itemAtPosition(start_x, start_y)->widget());
    QPushButton* finishButton = qobject_cast<QPushButton*>(gridLayout->itemAtPosition(finish_x, finish_y)->widget());
    if (startButton) startButton->setStyleSheet("background-color: green");
    if (finishButton) finishButton->setStyleSheet("background-color: red");
}

void MainWindow::on_explore_button_clicked()
{
    if(!is_map_valid()){
        QMessageBox::warning(this, "Warning", "No valid path found.");
        return;
    }

    int mode = 0;
    if(ui->Ex_rand_walk->isChecked() == true) mode = 1;
    else if(ui->Ex_rand_walkmem->isChecked() == true) mode = 2;
    else if(ui->Ex_DFS->isChecked() == true) mode = 3;
    else if(ui->Ex_BFS->isChecked() == true) mode = 4;
    else if(ui->Ex_A_star->isChecked() == true ) mode = 5;
    else QMessageBox::warning(this, "Warning", "Choose a mode please.");


    bool delay = true;

    if(mode == 1){
        int explored = 0;
        int steps = 0;
        if(ui->Delay_mode->isChecked()) delay = false;
        explore_randomwalk(explored, steps, delay);
        ui->output_statistics->append(" Explored: " + QString::number(explored) + " Steps: " + QString::number(steps));

    } else if(mode == 2){
        int explored = 0;
        int steps = 0;
        if(ui->Delay_mode->isChecked()) delay = false;
        explore_greedy_bfs(explored, steps, delay);
        ui->output_statistics->append(" Explored: " + QString::number(explored) + " Steps: " + QString::number(steps));

    } else if(mode == 3){
        int explored = 0;
        int steps = 0;
        if(ui->Delay_mode->isChecked()) delay = false;
        explore_dfs(explored, steps, delay);
        ui->output_statistics->append(" Explored: " + QString::number(explored) + " Steps: " + QString::number(steps));

    } else if(mode == 4){
        int explored = 0;
        int steps = 0;
        if(ui->Delay_mode->isChecked()) delay = false;
        explore_bfs(explored, steps, delay);
        ui->output_statistics->append(" Explored: " + QString::number(explored) + " Steps: " + QString::number(steps));

    } else if(mode == 5){
        int explored = 0;
        int steps = 0;
        if(ui->Delay_mode->isChecked()) delay = false;
        explore_A_star(explored, steps, delay);
        ui->output_statistics->append(" Explored: " + QString::number(steps) + " Shortest path: " + QString::number(explored));

    }

}

void MainWindow::on_pathfind_button_clicked()
{
    if(!is_map_valid()){
        QMessageBox::warning(this, "Warning", "No valid path found.");
        return;
    }

    int mode = 0;
    if(ui->Pf_BFS->isChecked() == true) mode = 1;
    else if(ui->Pf_DFS->isChecked() == true) mode = 2;
    else QMessageBox::warning(this, "Warning", "Choose a mode please.");


    int pathLength = 0;

    if(mode == 1) shortest_path_bfs(pathLength);
    else if(mode == 2) shortest_path_dfs(pathLength);
    ui->output_statistics->append("Shortest path length " + QString::number(pathLength));

}


void MainWindow::on_sim_button_clicked()
{
    simMode = new Simulation_mode(this);
    simMode->show();
}

void MainWindow::on_load_button_clicked()
{
    loadMode = new Load_mode(this);
    loadMode->show();
}

void MainWindow::on_tutoria_button_clicked()
{
    tutorial = new Tutorial(this);
    tutorial->show();
}
