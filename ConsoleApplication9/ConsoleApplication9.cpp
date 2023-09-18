#include <iostream>
#include <vector>

void printMatrix(const std::vector<std::vector<int>>& matrix) {
    for (const std::vector<int>& row : matrix) {
        for (int value : row) {
            std::cout << value << "\t";
        }
        std::cout << std::endl;
    }
}

std::vector<std::vector<int>> rotateClockwise90(const std::vector<std::vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    std::vector<std::vector<int>> rotated(cols, std::vector<int>(rows));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            rotated[j][rows - 1 - i] = matrix[i][j];
        }
    }

    return rotated;
}

std::vector<std::vector<int>> rotateCounterclockwise90(const std::vector<std::vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    std::vector<std::vector<int>> rotated(cols, std::vector<int>(rows));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            rotated[cols - 1 - j][i] = matrix[i][j];
        }
    }

    return rotated;
}
std::vector<std::vector<int>> rotate180(const std::vector<std::vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    std::vector<std::vector<int>> rotated(rows, std::vector<int>(cols));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            rotated[rows - 1 - i][cols - 1 - j] = matrix[i][j];
        }
    }

    return rotated;
}

std::vector<std::vector<int>> rotateClockwise270(const std::vector<std::vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    std::vector<std::vector<int>> rotated(cols, std::vector<int>(rows));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            rotated[cols - 1 - j][i] = matrix[i][j];
        }
    }

    return rotated;
}

int main() {
    int rows, cols;
    std::cout << "Enter the number of matrix rows: ";
    std::cin >> rows;
    std::cout << "Enter the number of matrix columns: ";
    std::cin >> cols;

    std::vector<std::vector<int>> matrix(rows, std::vector<int>(cols));

    int value = 1;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = value++;
        }
    }

    std::cout << "Initial matrix:" << std::endl;
    printMatrix(matrix);

    int choice;
    int rotationDirection; 
    do {
        std::cout << "\nRotate menu:\n";
        std::cout << "1. Rotate 90 degrees clockwise\n";
        std::cout << "2. Rotate 90 degrees counterclockwise\n";
        std::cout << "3. Rotate 180 degrees clockwise\n";
        std::cout << "4. Rotate 270 degrees clockwise\n";
        std::cout << "5. Rotate 360 degrees clockwise (without changes)\n";
        std::cout << "0. Exit\n";
        std::cout << "Choose an action: ";
        std::cin >> choice;

        if (choice == 1 || choice == 2) {
            std::cout << "Select rotation direction:\n";
            std::cout << "1. Clockwise\n";
            std::cout << "2. Counterclockwis\n";
            std::cout << "Choose a direction: ";
            std::cin >> rotationDirection;
        }

        switch (choice) {
        case 1:
            if (rotationDirection == 1) {
                matrix = rotateClockwise90(matrix);
                std::cout << "Rotate 90 degrees clockwise: \n";
            }
            else if (rotationDirection == 2) {
                matrix = rotateCounterclockwise90(matrix);
                std::cout << "Rotate 90 degrees counterclockwise: \n";
            }
            printMatrix(matrix);
            break;
        case 2:
            matrix = rotateCounterclockwise90(matrix);
            std::cout << "Rotate 90 degrees counterclockwise:\n";
            printMatrix(matrix);
            break;
        case 3:
            matrix = rotate180(matrix);
            std::cout << "Rotate 180 degrees clockwise:\n";
            printMatrix(matrix);
            break;
        case 4:
            matrix = rotateClockwise270(matrix);
            std::cout << "Rotate 270 degrees clockwise:\n";
            printMatrix(matrix);
            break;
        case 5:
            std::cout << "Rotate 360 degrees clockwise (without changes):\n";
            printMatrix(matrix);
            break;
        case 0:
            std::cout << "Exit the program.\n";
            break;
        default:
            std::cout << "Wrong choice. Try again.\n";
            break;
        }
    } while (choice != 0);

    return 0;
}