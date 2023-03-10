#include <iostream>
#include "point.h"

using namespace std;

// As per Professor Pat Miller's request, here is an example code and scenario for adding to the end, inserting, and deleting elements in dynamic arrays.
// I will not explain any of the code, rather you will look at it and **DRAW** it out and form your own understanding
// You are given permission to take *Inspiration* from and/or "copy" (without copy pasting) this code under two conditions:
	// *** You need to be able to explain what the code is doing either in a high-end level perspective or line-by-line. ***
		// If you can't, but you copy this code anyways, it will be considered academic dishonesty.
	// You will need to be able to implement it yourself by coding it *WITHOUT* looking at this code.
// Copying doesn’t help you, especially if you can’t understand and learn from it. You will only suffer in the long run by doing this.

int main() {
	int cap = 4, sz = 0;
	Point* line = new Point[cap];
	for (int i = 0; i < 13; i++) {
		if (cap == sz) {
			Point* newLine = new Point[cap * 2];
			for (int j = 0; j < sz; j++) {
				newLine[j] = line[j];
			}

			delete[] line;
			line = newLine;
			cap *= 2;
		}
		
		line[i] = Point(i, i);
		sz++;
	}

	for (int i = 0; i < 5; i++) {
		int indx = i*13 % (sz + 1);
		if (cap == sz) {
			Point* newLine = new Point[cap * 2];
			for (int j = 0; j < sz; j++) {
				if (j >= indx) newLine[j+1] = line[j];
				else newLine[j] = line[j];
			}

			delete[] line;
			line = newLine;
			cap *= 2;
		}
		else {
			for (int j = sz + 1; j > indx; j--) {
				line[j] = line[j-1];
			}
		}
		
		line[indx] = Point(i, i);
		sz++;
	}

	for (int i = 0; i < 7; i++) {
		int indx = i*13 % (sz + 1);
		for (int j = indx; j < sz-1; j++) {
			line[j] = line[j+1];
		}

		sz--;
	}
}