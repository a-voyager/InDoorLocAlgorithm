#include <iostream>
#include <cmath>
#include <stdlib.h>

using namespace std;

class Detector {
private:
	float accValue[100];
	int i;
	float accSum;
	float accMin;
public:

	Detector() {
		i = 0;
		accSum = 0;
		accMin = 0;
	}

	void onAccChanged(float x, float y, float z, float pitch) {
		accSum = 1.0*sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
		cout << accSum << endl;
		accValue[i] = accSum;


		if (accSum>1.9*9.8) {
			accMin = findMin(accValue, i + 1);
			cout << "*******" << accMin << endl;
			if (accMin<0.6*9.8) {
				if (90.0 - pitch<60) {
					cout << "Ë¤µ¹" << endl;
				}

			}


		}
		++i % 100;

	}

	float findMin(float arr[], int len) {
		float min = arr[0];
		for (int i = 0; i<len; i++) {
			min = arr[i]<min ? arr[i] : min;
			cout << "arr[" << i << "] = " << arr[i] << endl;
		}
		return min;
	}
	 
};

int main() {
	Detector *d = new Detector();
	d->onAccChanged(0.2, 0.5, 0.7, 80.0);
	d->onAccChanged(0.2, 8.8, 0.9, 50.0);
	d->onAccChanged(0.2, 0.4, 0.5, -30.0);
	d->onAccChanged(0.9, 0.5, 0.7, 20.0);


	delete d;
	system("pause");
	return 0;
}