/*
 * GridTest.cpp
 *
 *  Created on: Aug 21, 2014
 *      Author: nickhathaway
 */

#include "GridTest.hpp"


GridTest::GridTest():b1("b1"), b2("b2"), b3("b3"), b4("b4") {
	//set_border_width(100);
	attach(b1, 1,1,1,1);
	attach(b2, 2,1,1,1);
	attach(b3, 3,1,1,1);
	attach(b4, 4,1,1,1);

	b1.show();
	b2.show();
	b3.show();
	b4.show();


}
