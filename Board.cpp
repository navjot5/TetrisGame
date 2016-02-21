//Navjot Singh ID 912224741
#include <iostream>
#include <vector>
#include <stdexcept>
#include "Board.h"

using namespace std;

void Board::draw(void) const{
	cout<< "<?xml version=\"1.0\" encoding=\"utf-8\"  standalone=\"no\"?>"<<endl;
	cout<< "<!DOCTYPE svg PUBLIC \"-//W3C//DTD SVG 1.1//EN\" "<<endl;
	cout<< "\"http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd\"> "<<endl;
	cout<< "<svg width=\"570\" height=\"570\" viewBox=\"0 0 550 550\" "<<endl;
	cout<< "xmlns=\"http://www.w3.org/2000/svg\" "<<endl;
	cout<< "xmlns:xlink=\"http://www.w3.org/1999/xlink\" >"<<endl;
	cout<< "<g transform=\"matrix(1,0,0,-1,50,550)\">"<<endl;

	cout<< "<rect fill=\"white\" stroke=\"black\" x=\"0\" y=\"0\"  width=\""<<size_x*50<<"\" height=\""<<size_y*50<<"\"/>"<<endl;

		
	for(unsigned int i=0;i<tList.size();i++){
		tList[i] -> draw();
	}

	cout<< "</g>" << endl;
	cout<< "</svg>"<< endl;

}

bool Board::fits_on_board(const Tetromino &t) const{
	

	for (int i=0; i<4;i++){
   		if (t.getX(i) >= size_x){
   			return false;
   	}
   	   if(t.getY(i) >= size_y){
		return false;
	}
		if(t.getX(i)<0 || t.getY(i)<0){
			return false;
		}
	else{
   		return true;
   }
}
return 0;
}

void Board::addTetromino(char type, int x, int y, int orientation){
	
    Tetromino *t = Tetromino::makeTetromino(type, x, y, orientation);
	if(fits_on_board(*t)== true) {
		vector<Tetromino *>::iterator iter;
		for(iter = tList.begin(); iter != tList.end(); iter++) {
			if((*iter) -> overlap(*t)== false){}
			
			else{
				throw invalid_argument("overlap");
			}
		}
		tList.push_back(t);
    }
   else {
   	   throw invalid_argument("does not fit on the board");
    }
}
 


 


