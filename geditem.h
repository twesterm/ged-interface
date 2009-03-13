#ifndef GEDITEM_H
#define GEDITEM_H

#include <QListWidgetItem>

class GEDItem : public QListWidgetItem
{
public:
    GEDItem();
private:
      QString IPLA, IXMA, JYMA;
      QString PIXEL, XPIXFA, YPIXFA, XSCAT, YSCAT, XNULL, YNULL, RMIN, RMAX, DR, RMINT, RMAXT, DRT, TUNEXP, RADI, CADIST;
      QString WAVE, DELTAS, SEPLA, ISECT, IRECOA, IRECOA2, ANGLE;
      bool Useable;
      QString Path;
  public:
    bool setIPLA(QString);
    bool setIXMA(QString);
    bool setJYMA(QString);
    bool setPIXEL(QString);
    bool setXPIXFA(QString);
    bool setYPIXFA(QString);
    bool setXSCAT(QString);
    bool setYSCAT(QString);
    bool setANGLE(QString);
    bool setXNULL(QString);
    bool setYNULL(QString);
    bool setRMIN(QString);
    bool setRMAX(QString);
    bool setDR(QString);
    bool setRMINT(QString);
    bool setRMAXT(QString);
    bool setDRT(QString);
    bool setTUNEXP(QString);
    bool setRADI(QString);
    bool setCADIST(QString);
    bool setIRECOA(QString);
    bool setIRECOA2(QString);
    bool setSEPLA(QString);
    bool setISECT(QString);
    bool setWAVE(QString);
    bool setDELTAS(QString);
    void setPath(QString);
    void setUseable(bool);

    QString getIPLA();
    QString getIXMA();
    QString getJYMA();
    QString getPIXEL();
    QString getXPIXFA();
    QString getYPIXFA();
    QString getXSCAT();
    QString getYSCAT();
    QString getANGLE();
    QString getXNULL();
    QString getYNULL();
    QString getRMIN();
    QString getRMAX();
    QString getDR();
    QString getRMINT();
    QString getRMAXT();
    QString getDRT();
    QString getTUNEXP();
    QString getRADI();
    QString getCADIST();
    QString getIRECOA();
    QString getIRECOA2();
    QString getSEPLA();
    QString getISECT();
    QString getPath();
    QString getWAVE();
    QString getDELTAS();
    bool isUseable();

};

#endif // GEDITEM_H
