#include <iostream>
using namespace std;

float getGradePoint(char grade) {
    switch (grade) {
        case 'A': return 4.0;
        case 'B': return 3.0;
        case 'C': return 2.0;
        case 'D': return 1.0;
        case 'F': return 0.0;
        default: return 0.0;
    }
}

int main() {
    int n;
    cout << "Enter number of courses: ";
    cin >> n;

    // dynamic arrays (no vector)
    char* grade = new char[n];
    int* credit = new int[n];

    float totalCredits = 0;
    float totalGradePoints = 0;

    for (int i = 0; i < n; i++) {
        cout << "\nCourse " << i + 1 << endl;

        cout << "Enter grade (A/B/C/D/F): ";
        cin >> grade[i];

        cout << "Enter credit hours: ";
        cin >> credit[i];

        float gp = getGradePoint(grade[i]);

        totalCredits += credit[i];
        totalGradePoints += gp * credit[i];
    }

    cout << "\n--- Course Details ---\n";
    for (int i = 0; i < n; i++) {
        cout << "Course " << i + 1
             << " | Grade: " << grade[i]
             << " | Credit Hours: " << credit[i] << endl;
    }

    float cgpa = totalGradePoints / totalCredits;

    cout << "\nFinal CGPA: " << cgpa << endl;

    // free memory
    delete[] grade;
    delete[] credit;

    return 0;
}
