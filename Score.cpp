#include "Score.h"
#include <QFont>

Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent){
    // mettre score a 0
    score = 0;

    // ajouter text
    setPlainText(QString("Score: ") + QString::number(score)); // Score: 0
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",16));
}

void Score::increase(){
    score++;
    setPlainText(QString("Score: ") + QString::number(score)); // Score: 1
}

int Score::getScore(){
    return score;
}

#include "stdafx.h"
#include "math.h"
#include <Windows.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Variables
string PlayerName="Name1";
int PlayerScore=200;

int main()
{
    ofstream HighScoreFile;
    HighScoreFile.open("example.txt");
    HighScoreFile << "\t\t\t" << score << "\n";
    HighScoreFile.close();

    HighScoreFile.seekp(0,std::ios::end); //to ensure the put pointer is at the end
    HighScoreFile<<"\t\t\t" << score;

return 0;
}
