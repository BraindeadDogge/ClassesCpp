#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Currency {
private:
	string name;
	vector<double> history;
public:
	void setname(string eman) {
		name = eman;
	}
	void setrate(double etar) {
		if (etar < 0)
			etar = 1;
		history.push_back(etar);
	}
	string getname() {
		return name;
	}
	double convert(double num) {
		return num * history.back();
	}
	vector<double> gethistory() {
		return history;
	}
	double gethistory(int n) {
		if (n >= history.size())
			return history.back();
		else
			return history[n];
	}

};

int main() {
	Currency c[2];
	double x;
	string y;
	cin >> y >> x;
	c[0].setname(y);
	c[0].setrate(x);
	cin >> y >> x;
	c[1].setname(y);
	c[1].setrate(x);
	int n, number, one_more_number;
	string command;
	cin >> n;
	while (n) {
		cin >> command;
		if (command == "set_rate") {
			cin >> number >> x;
			c[number - 1].setrate(x);
		}
		else if (command == "set_name") {
			cin >> number >> y;
			c[number - 1].setname(y);
		}
		else if (command == "show") {
			cin >> number;
			cout << c[number - 1].getname() << " " << c[number - 1].gethistory(100000000) << endl;
		}
		else if (command == "convert") {
			cin >> x >> command >> number;
			cout << c[number - 1].convert(x) << endl;
		}
		else if (command == "History") {
			cin >> number;
			for (int i = 0; i < c[number - 1].gethistory().size(); ++i)
				cout << c[number - 1].gethistory()[i] << " ";
			cout << endl;
		}
		else if (command == "history") {
			cin >> number >> command >> one_more_number;
			cout << c[number - 1].gethistory(one_more_number) << endl;
		}
		--n;
	}
	system("PAUSE");
	return 0;
}
