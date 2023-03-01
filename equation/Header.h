#pragma once
#include <iostream>
#include <fstream>
#include <vector>

void read(std::vector<double>& line) {
    std::ifstream in("input.txt");
    double n = 0;
    while (!in.eof())
    {
        in >> n;
        line.push_back(n);
    }
    in.close();//dfsg
}

void write(std::vector<double> line) {
    std::ofstream out("output.txt");
    if (out.is_open()) {
        for (int i = 0; i < line.size(); i++) {
            out << line[i] << '\t';
        }
        out << std::endl;
    }
    out.close();
}

double discriminant(std::vector <double> line) {
    int d = line.size();
    if (d == 0)
        return 0;
    double t = line[1] * line[1] - 4 * line[0] * line[2];
    return t;
}

double search(double discriminant, std::vector<double> line) {
    std::vector<double> solution;
    if (discriminant < 0) {
        std::cout << "There are no solutions in the field of real numbers\n";
        std::ofstream out("output.txt");
        out << "There are no solutions in the field of real numbers\n";
        return 0;
    }
    else {
        if (discriminant == 0) {
            solution.resize(1);
            solution[0] = (-line[1]) / (2 * line[0]);
        }
        else {
            solution.resize(2);
            solution[0] = (-line[1]) - sqrt(discriminant) / (2 * line[0]);
            solution[1] = (-line[1]) + sqrt(discriminant) / (2 * line[0]);
        }
    }
    write(solution);
}
