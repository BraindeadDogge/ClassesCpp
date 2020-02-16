#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

class Mark {
public:
	int score;
	int weight;
	string comment;
	void read() {
		cin >> score >> weight >> comment;
	}
};

class Diary {
public:
	vector<Mark> diary;
	void add() {
		Mark tmp;
		tmp.read();
		diary.push_back(tmp);
	}
	float average() {
		double count = 0, counter = 0;
		for (int i = 0; i < diary.size(); ++i) {
			count += diary[i].score * diary[i].weight;
			counter += diary[i].weight;
		}
		count /= counter;
		if (counter)
			return count;
		else
			return 0;
	}
};

class Student {
public:
	string name;
	Diary diary;
	void get_mark() {
		diary.add();
	}
	void average_score() {
		cout << name << ": ";
		cout << fixed << setprecision(2) << diary.average() << endl;
	}
};

class Group {
public:
	vector<Student> students;
	int number;
	void add_mark(string name) {
		for (int i = 0; i < students.size(); ++i)
		if (students[i].name == name)
			students[i].get_mark();
	}
	void add_student(string name) {
		Student tmp;
		tmp.name = name;
		students.push_back(tmp);
	}
	void average_score(string name) {
		double counter = 0;
		if (name == "total") {
			for (int i = 0; i < students.size(); ++i) {
				counter += students[i].diary.average();
			}
			if (students.size())
				counter /= students.size();
			else
				counter = 0;
			cout << number << ": " << fixed << setprecision(2) << counter << endl;
		}
		else {
			for (int i = 0; i < students.size(); ++i) {
				if (students[i].name == name) {
					cout << number << " ";
					students[i].average_score();
				}
			}
		}
	}
};

int main() {
	vector<Group> groups;
	string comment;
	int count;
	int a;
	cin >> a;
	while (a) {
		cin >> comment;
		if (comment == "new") {
			cin >> comment;
			if (comment == "group") {
				Group tmp;
				cin >> count;
				for (int i = 0; i < count; ++i) {
					cin >> comment;
					tmp.add_student(comment);
				}
				tmp.number = groups.size() + 1;
				groups.push_back(tmp);
			}
			else if (comment == "student") {
				cin >> count >> comment;
				groups[count - 1].add_student(comment);
			}
		}
		else if (comment == "add") {
			cin >> count >> comment;
			groups[count - 1].add_mark(comment);
		}
		else if (comment == "average") {
			cin >> count >> comment;
			groups[count - 1].average_score(comment);
		}
		--a;
	}
	system("PAUSE");
	return 0;
}
