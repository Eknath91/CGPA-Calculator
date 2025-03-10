#include <iostream>
using namespace std;

class CGPACalculator {
private:
    int numSubjects;
    float totalGradePoints;
    float totalCredits;

public:
    CGPACalculator() : numSubjects(0), totalGradePoints(0.0), totalCredits(0.0) {}

    void inputSubjects() {
        cout << "Enter the number of subjects: ";
        cin >> numSubjects;

        for (int i = 0; i < numSubjects; i++) {
            float gradePoint, credit;
            cout << "Enter grade point for subject " << (i + 1) << ": ";
            cin >> gradePoint;
            cout << "Enter credit for subject " << (i + 1) << ": ";
            cin >> credit;

            totalGradePoints += (gradePoint * credit);
            totalCredits += credit;
        }
    }

    float calculateSGPA() {
        return (totalCredits == 0) ? 0.0 : totalGradePoints / totalCredits;
    }

    float getTotalGradePoints() const { return totalGradePoints; }
    float getTotalCredits() const { return totalCredits; }
};

int main() {
    int semesters;
    cout << "Enter the number of semesters: ";
    cin >> semesters;

    float totalGradePoints = 0.0, totalCredits = 0.0;

    for (int i = 0; i < semesters; i++) {
        cout << "\nSemester " << (i + 1) << " details:\n";
        CGPACalculator semester;
        semester.inputSubjects();
        float sgpa = semester.calculateSGPA();
        cout << "SGPA for Semester " << (i + 1) << ": " << sgpa << "\n";

        totalGradePoints += semester.getTotalGradePoints();
        totalCredits += semester.getTotalCredits();
    }

    float cgpa = (totalCredits == 0) ? 0.0 : totalGradePoints / totalCredits;
    cout << "\nFinal CGPA: " << cgpa << endl;

    return 0;
}
