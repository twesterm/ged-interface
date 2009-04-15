      SUBROUTINE SCENT(JMAMA,IMAMA,
     +              IMAX,LINJER,COUNT,DXLEN,AVSTAN,DR,RMIN,
     +              RMAX,XNULL,YNULL,RAVX,RAVY)
CCCCC
C
C     MODIFIED FOR PSCANO TOR G. STRAND 030129:     
C
C     FROM IDEALLY RADIAL SYMMETRIC VALUES AROUND XNULL AND YNULL
C     IN COUNT(I,J), AND AVERAGES ALONG X AND Y AXIS ARE COMPUTED TO 
C     RAVX(I) AND RAVY(I) FROM -RMAX TO RMAX IN INTERVALS DR.  
C
C     XNULL AND YNULL COORDINATES OF CENTER WITH ORIGO AT LOWER
C     LEFT CORNER, COUNT(1,1).  BASED ON SCENT2.FOR.
C
C     TOR G. STRAND 970909-971030.
C     TOR G. STRAND 001214.
C
CCCCC
C
C 
      DIMENSION COUNT(JMAMA,IMAMA),RAVX(*),RAVY(*),
     +          NORIY(2000),NORIX(2000)
C
C     ZEROING NORI()'s:
C
      IRTOT = 1.001 + (2.0*RMAX)/DR
      DO I = 1,IRTOT
         NORIX(I)  = 0
         RAVX(I) = 0.0
         NORIY(I)  = 0
         RAVY(I) = 0.0
      ENDDO
C
C     LOOP OVER COUNT, RAV's AND SETTING NORI()'s:
C
      DO I = 1,IMAX
         XIX = FLOAT(I-1)*DXLEN - XNULL
         DO J = 1,LINJER
            YJY = FLOAT(J-1)*AVSTAN - YNULL
            RIJ = SQRT(XIX**2 + YJY**2)
            IF (RIJ.LT.RMIN-0.5*DR .OR. RIJ.GT.RMAX+0.5*DR) THEN
               GO TO 100
            ENDIF
C
C     1. QADRANT:
C
            IF(XIX.GT.0.0 .AND. YJY.GT.0.0) THEN
               IRIJ = 1.00 + (RMAX + RIJ + 0.5*DR)/DR
               NORIX(IRIJ) = NORIX(IRIJ) + 1
               NORIY(IRIJ) = NORIY(IRIJ) + 1
               RAVY(IRIJ) = RAVY(IRIJ) + COUNT(J,I)
               RAVX(IRIJ) = RAVX(IRIJ) + COUNT(J,I)
C
C     2. QUADRANT:
C
            ELSE IF(XIX.LT.0.0 .AND. YJY.GT.0.0) THEN
               IRIJ = 1.00 + (RMAX + RIJ + 0.5*DR)/DR
               NORIY(IRIJ) = NORIY(IRIJ) + 1
               RAVY(IRIJ) = RAVY(IRIJ) + COUNT(J,I)
               IRIJ = 1.00 + (RMAX - RIJ + 0.5*DR)/DR
               NORIX(IRIJ) = NORIX(IRIJ) + 1
               RAVX(IRIJ) = RAVX(IRIJ) + COUNT(J,I)
C
C     3. QUADRANT:
C
            ELSE IF(XIX.LT.0.0 .AND. YJY.LT.0.0) THEN
               IRIJ = 1.00 + (RMAX - RIJ + 0.5*DR)/DR
               NORIY(IRIJ) = NORIY(IRIJ) + 1
               RAVY(IRIJ) = RAVY(IRIJ) + COUNT(J,I)
               NORIX(IRIJ) = NORIX(IRIJ) + 1
               RAVX(IRIJ) = RAVX(IRIJ) + COUNT(J,I)
C
C     4. QUADRANT:
C
            ELSE
               IRIJ = 1.00 + (RMAX - RIJ + 0.5*DR)/DR
               NORIY(IRIJ) = NORIY(IRIJ) + 1
               RAVY(IRIJ) = RAVY(IRIJ) + COUNT(J,I)
               IRIJ = 1.00 + (RMAX + RIJ + 0.5*DR)/DR
               NORIX(IRIJ) = NORIX(IRIJ) + 1
               RAVX(IRIJ) = RAVX(IRIJ) + COUNT(J,I)
            ENDIF
  100       CONTINUE
         ENDDO
      ENDDO
C
C     AVERAGES TO RAV*(IR):
C
      DO I = 1,IRTOT
         NORIJ = NORIX(I)
         IF (NORIJ.GE.1) THEN
            RAVX(I) = RAVX(I)/FLOAT(NORIJ)
         ENDIF
         NORIJ = NORIY(I)
         IF (NORIJ.GE.1) THEN
            RAVY(I) = RAVY(I)/FLOAT(NORIJ)
         ENDIF
      ENDDO
C
C
      RETURN
      END
      