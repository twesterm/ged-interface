#include "geditem.h"
#include "qstring.h"

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
     this->setXNULL("130.0");
     this->setYNULL("110.0");
     this->setRMIN("8.0");
     this->setRMAX("55.0");
     this->setDR("0.1");
     this->setRMINT("8.5");
     this->setRMAXT("58.0");
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

     setUseable(false);
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
    QString GEDItem::getDRT(){return this->RMAXT;}
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
    bool GEDItem::isUseable(){return this->Useable;}

