#include "geditem.h"
#include "qstring.h"
#include <iostream>
#include <fstream>
#include <math.h>
#include <QStringList>
#include <QTextStream>
#include <QFile>
#define PI 3.14159265

GEDItem::GEDItem()
{
     this->setIPLA("1");
     this->setIXMA("4000");
     this->setJYMA("3000");
     this->setPIXEL("0.05");
     this->setXPIXFA("1.0");
     this->setYPIXFA("1.0");
     this->setXSCAT("130.0");
     this->setYSCAT("110.0");
     this->setANGLE("0.0");
     this->setXNULL("0");
     this->setYNULL("0");
     this->setRMIN("8.0");
     this->setRMAX("55.0");
     this->setDR("0.1");
     this->setRMINT("0.0");
     this->setRMAXT("0.0");
     this->setDRT("0.1");
     this->setTUNEXP("0.0");
     this->setRADI("0.0");
     this->setCADIST("501.88");
     this->setWAVE("0.04855");
     this->setDELTAS("0.2");
     this->setIRECOA("1");
     this->setIRECOA2("3.0");
     this->setSEPLA("4.24");
     this->setISECT("3");
     this->setSECFI("/usr/local/lib/GED/isect3.bin");

     this->setUseable(false);
     this->setMode("none");
}
    void GEDItem::setPath(QString text)
    {
        this->Path=text;
    }

    bool GEDItem::setIPLA(QString text)
    {
        bool ok;
        int tmp;
        tmp = text.toInt(&ok);
        if ((tmp>0) && ok )
        {
           this->IPLA=text;
           return true;
        }
        else return false;
    }

    bool GEDItem::setIXMA(QString text)
    {
        bool ok;
        float tmp;
        tmp = text.toFloat(&ok);
        if ((tmp>=0.0) && ok )
        {
           this->IXMA=text;
           return true;
        }
        else return false;
    }
    bool GEDItem::setJYMA(QString text)
    {
        bool ok;
        float tmp;
        tmp = text.toFloat(&ok);
        if ((tmp>=0.0) && ok )
        {
           this->JYMA=text;
           return true;
        }
        else return false;
    }
    bool GEDItem::setPIXEL(QString text)
    {
        bool ok;
        float tmp;
        tmp = text.toFloat(&ok);
        if ((tmp>=0.0) && ok )
        {
           this->PIXEL=text;
           return true;
        }
        else return false;
    }
    bool GEDItem::setXPIXFA(QString text)
    {
        bool ok;
        float tmp;
        tmp = text.toFloat(&ok);
        if ((tmp>=0.0) && ok )
        {
           this->XPIXFA=text;
           return true;
        }
        else return false;
    }
    bool GEDItem::setYPIXFA(QString text)
    {
        bool ok;
        float tmp;
        tmp = text.toFloat(&ok);
        if ((tmp>=0.0) && ok )
        {
           this->YPIXFA=text;
           return true;
        }
        else return false;
    }
    bool GEDItem::setXSCAT(QString text)
    {
        bool ok;
        float tmp;
        tmp = text.toFloat(&ok);
        if ((tmp>=0.0) && ok )
        {
           this->XSCAT=text;
           return true;
        }
        else return false;
    }
    bool GEDItem::setYSCAT(QString text)
    {
        bool ok;
        float tmp;
        tmp = text.toFloat(&ok);
        if ((tmp>=0.0) && ok )
        {
           this->YSCAT=text;
           return true;
        }
        else return false;
    }

     bool GEDItem::setANGLE(QString text)
    {
        bool ok;
        float tmp;
        tmp = text.toFloat(&ok);
        if ((tmp>=0.0) && ok )
        {
           this->ANGLE=text;
           return true;
        }
        else return false;
    }
    bool GEDItem::setXNULL(QString text)
    {
        bool ok;
        float tmp;
        tmp = text.toFloat(&ok);
        if ((tmp>0.0) && ok )
        {
           this->XNULL=text;
           return true;
        }
        else return false;
    }
    bool GEDItem::setYNULL(QString text)
    {
        bool ok;
        float tmp;
        tmp = text.toFloat(&ok);
        if ((tmp>0.0) && ok )
        {
           this->YNULL=text;
           return true;
        }
        else return false;
    }
    bool GEDItem::setRMIN(QString text)
    {
        bool ok;
        float tmp = text.toFloat(&ok);
        if ((tmp>=0.0) && ok )
        {
           this->RMIN=text;
           return true;
        }
        else return false;
    }
    bool GEDItem::setRMAX(QString text)
    {
        bool ok;
        float tmp = text.toFloat(&ok);
        if ((tmp>=0.0) && ok )
        {
           this->RMAX=text;
           return true;
        }
        else return false;
    }
    bool GEDItem::setDR(QString text)
    {
        bool ok;
        float tmp = text.toFloat(&ok);
        if ((tmp>=0.0) && ok )
        {
           this->DR=text;
           return true;
        }
        else return false;
    }
    bool GEDItem::setRMINT(QString text)
    {
        bool ok;
        float tmp = text.toFloat(&ok);
        if ((tmp>=0.0) && ok )
        {
           this->RMINT=text;
           return true;
        }
        else return false;
    }

    bool GEDItem::setRMAXT(QString text)
    {
        bool ok;
        float tmp = text.toFloat(&ok);
        if ((tmp>=0.0) && ok )
        {
           this->RMAXT=text;
           return true;
        }
        else return false;
    }
    bool GEDItem::setDRT(QString text)
    {
        bool ok;
        float tmp = text.toFloat(&ok);
        if ((tmp>=0.0) && ok )
        {
           this->DRT=text;
           return true;
        }
        else return false;
    }
    bool GEDItem::setTUNEXP(QString text)
    {
        bool ok;
        float tmp = text.toFloat(&ok);
        if ((tmp>=0.0) && ok )
        {
           this->TUNEXP=text;
           return true;
        }
        else return false;
    }
    bool GEDItem::setRADI(QString text)
    {
        bool ok;
        float tmp = text.toFloat(&ok);
        if ((tmp>=0.0) && ok )
        {
           this->RADI=text;
           return true;
        }
        else return false;
    }
    bool GEDItem::setCADIST(QString text)
    {
        bool ok;
        float tmp = text.toFloat(&ok);
        if ((tmp>=0.0) && ok )
        {
           this->CADIST=text;
           return true;
        }
        else return false;
    }

    bool GEDItem::setWAVE(QString text)
    {
        bool ok;
        float tmp = text.toFloat(&ok);
        if ((tmp>=0.0) && ok )
        {
           this->WAVE=text;
           return true;
        }
        else return false;
    }
    bool GEDItem::setDELTAS(QString text)
    {
        bool ok;
        float tmp = text.toFloat(&ok);
        if ((tmp>=0.0) && ok )
        {
           this->DELTAS=text;
           return true;
        }
        else return false;
    }
    bool GEDItem::setIRECOA(QString text)
    {
        bool ok;
        float tmp = text.toFloat(&ok);
        if ((tmp>=0.0) && ok )
        {
           this->IRECOA=text;
           return true;
        }
        else return false;
    }
    bool GEDItem::setIRECOA2(QString text)
    {
        bool ok;
        float tmp = text.toFloat(&ok);
        if ((tmp>=0.0) && ok )
        {
           this->IRECOA2=text;
           return true;
        }
        else return false;
    }

    bool GEDItem::setSEPLA(QString text)
    {
        bool ok;
        float tmp = text.toFloat(&ok);
        if ((tmp>=0.0) && ok )
        {
           this->SEPLA=text;
           return true;
        }
        else return false;
    }

    bool GEDItem::setISECT(QString text)
    {
        bool ok;
        int tmp = text.toInt(&ok);
        if ((tmp>=0) && ok )
        {
           this->ISECT=text;
           return true;
        }
        else return false;
    }

    void GEDItem::setUseable(bool value)
    {
        this->Useable=value;
    }

    void GEDItem::setMode(QString mode) {
        this->Mode=mode;
    }
    void GEDItem::setxRMAXT(QString x) {
        this->xRMAXT=x;
    }
    void GEDItem::setyRMAXT(QString y) {
        this->yRMAXT=y;
    }

    void GEDItem::setyAngle(QString y) {
        this->yAngle=y;
    }
    void GEDItem::setxAngle(QString x) {
        this->xAngle=x;
    }
    void GEDItem::setSECFI(QString path) {
        this->SECFI=path ;
    }

    QString GEDItem::getIPLA(){return this->IPLA;}
    QString GEDItem::getIXMA(){return this->IXMA;}
    QString GEDItem::getJYMA(){return this->JYMA;}
    QString GEDItem::getPIXEL(){return this->PIXEL;}
    QString GEDItem::getXPIXFA(){return this->XPIXFA;}
    QString GEDItem::getYPIXFA(){return this->YPIXFA;}
    QString GEDItem::getXSCAT(){return this->XSCAT;}
    QString GEDItem::getYSCAT(){return this->YSCAT;}
    QString GEDItem::getANGLE(){return this->ANGLE;}
    QString GEDItem::getXNULL(){return this->XNULL;}
    QString GEDItem::getYNULL(){return this->YNULL;}
    QString GEDItem::getRMIN(){return this->RMIN;}
    QString GEDItem::getRMAX(){return this->RMAX;}
    QString GEDItem::getDR(){return this->DR;}
    QString GEDItem::getRMINT(){return this->RMINT;}
    QString GEDItem::getRMAXT(){return this->RMAXT;}
    QString GEDItem::getDRT(){return this->DRT;}
    QString GEDItem::getTUNEXP(){return this->TUNEXP;}
    QString GEDItem::getRADI(){return this->RADI;}
    QString GEDItem::getCADIST(){return this->CADIST;}
    QString GEDItem::getIRECOA(){return this->IRECOA;}
    QString GEDItem::getIRECOA2(){return this->IRECOA2;}
    QString GEDItem::getSEPLA(){return this->SEPLA;}
    QString GEDItem::getISECT(){return this->ISECT;}
    QString GEDItem::getWAVE(){return this->WAVE;}
    QString GEDItem::getDELTAS(){return this->DELTAS;}
    QString GEDItem::getPath(){return this->Path;}
    QString GEDItem::getMode(){return this->Mode;}
    bool GEDItem::isUseable(){return this->Useable;}
    QString GEDItem::getxAngle(){return this->xAngle;}
    QString GEDItem::getyAngle(){return this->yAngle;}
    QString GEDItem::getxRMAXT(){return this->xRMAXT;}
    QString GEDItem::getyRMAXT(){return this->yRMAXT;}
    QString GEDItem::getSECFI(){return this->SECFI;}



    float GEDItem::distance(float x1, float x2, float y1, float y2) { // this method calcs the distance between two points
        float result = sqrt(pow(x1-x2, 2)+pow(y1-y2,2));
        return result;
    }

    float GEDItem::scalePixel(int pixel, QString mode) {
        // get a pixel and returns the value in mm
        // mode: x, y
        if (mode == "x") {
            float scaled = pixel* this->XPIXFA.toFloat() * this->PIXEL.toFloat();
            return scaled;
        } else {
            float scaled = pixel * this->YPIXFA.toFloat() * this->PIXEL.toFloat();
            return scaled;
        }
    }

    float GEDItem::calcAngle(float x1, float y1, float x2, float y2, float x3, float y3) {
        float c = this->distance(x1, x2, y1, y2);
        float b = this->distance(x1, x3, y1, y3);
        float a = this->distance(x2, x3, y2, y3);

        float angle = 0.0;
        if (b > 0.0 && c > 0.0) {
           angle = acos((b*b+c*c - a*a)/(2*b*c))* 180.0/PI;
       }
        return angle;
    }

   using namespace std;
   QString GEDItem::writeInputFile(QString outDir) { // writes  input file and return the path of the input file.
       QStringList list = this->getPath().split("/");
       QString SECFIfile,  curveFile, plotFile, inputFile, dataFile;
       QString baseName = "/";
       int mode;
       if (this->getMode() == "Whole area" || this->getMode() == "Top-Down" || this->getMode() == "Right-Left") {
           mode = 1;
       } else if (this->getMode() == "Top" || this->getMode() == "Left") {
           mode = 2;
       } else if (this->getMode() == "Right" || this->getMode() == "Down") {
           mode = 3;
       } else return "";
       dataFile = this->getPath();
       dataFile.chop(4); // removes .tif
       dataFile.append(".img");
       curveFile = outDir + this->text() + ".curv";
       plotFile = outDir + this->text() + ".plot";
       inputFile = outDir + this->text() + ".txt";
       QString infoFile = outDir + this->text() + ".info";
       //this->inputFiles.append(inputFile);

       QFile myfile(inputFile);
       if (!myfile.open(QIODevice::WriteOnly | QIODevice::Text))
         return "";

       QTextStream out(&myfile);
 //      out << "The magic number is: " << 49 << "\n";
       out <<  this->getIXMA() << "\n";
       out <<  this->getJYMA()<< "\n";
       out <<  this->torealFLoat(this->getPIXEL())<< "\n";
       out <<  this->torealFLoat(this->getXPIXFA()) << "\n";
       out <<  this->torealFLoat(this->getYPIXFA())<< "\n";
       out <<  this->torealFLoat(this->getXSCAT()) << "\n";
       out <<  this->torealFLoat(this->getYSCAT()) <<  "\n";
       out <<  this->torealFLoat(this->getANGLE()) << "\n";
       out <<  this->torealFLoat(this->getXNULL()) << "\n";
       out <<  this->torealFLoat(this->getYNULL()) << "\n";
       out <<  this->torealFLoat(this->getRMIN()) << "\n";
       out <<  this->torealFLoat(this->getRMAX()) <<  "\n";
       out <<  this->torealFLoat(this->getDR()) << "\n";
       out <<  this->torealFLoat(this->getRMINT()) << "\n";
       out <<  this->torealFLoat(this->getRMAXT()) <<  "\n";
       out <<  this->torealFLoat(this->getDRT()) << "\n";
       out <<  this->getIRECOA() << "\n";
       out <<  this->torealFLoat(this->getIRECOA2())<< "\n";
       out <<  this->torealFLoat(this->getTUNEXP())<< "\n";
       out << this->torealFLoat(this->getRADI())<< "\n";
       out << this->torealFLoat( this->getCADIST()) << "\n";
       out <<  this->torealFLoat(this->getWAVE()) <<  "\n";
       out <<  this->torealFLoat(this->getDELTAS()) << "\n";
       out <<  this->torealFLoat(this->getSEPLA()) << "\n";
       out <<  this->getISECT()<< "\n";
       out << mode << "\n";
       out << dataFile<< "\n";
       out << curveFile << "\n";
       out << plotFile << "\n";
       out << this->getSECFI() << "\n";
       out << infoFile << "\n";
       myfile.close();
       return inputFile;
   }


   QString GEDItem::torealFLoat(QString value) {
       if (value.contains(".", Qt::CaseInsensitive)) {
           return value;
       } else {
           value.append(".0");
           return value;
       }
   }








