      SUBROUTINE SCENTC(IMAMA,JMAMA,
     +              IMAX,LINJER,COUNT,DXLEN,AVSTAN,DR,RMIN,
     +              RMAX,XMAX,YMAX,ANGLE,XNULL,YNULL,RSIG,
     +              RAVRA,IRECOA,FACOA,NOTOT,NOECOA,NORI,RUNAV,
     +              SMIN,SMAX,DELTAS,CADIST,WAVLE)
CCCCCC
C
C     FROM IDEALLY RADIAL SYMMETRIC VALUES AROUND XNULL AND YNULL
C     IN COUNT(J,I), STANDARD DEVIATION, RSIG(I), AND AVERAGES
C     RAVRA(I) IS COMPUTED FROM SMIN TO SMAX IN INTERVALS DELTAS.  
C
C     XNULL AND YNULL COORDINATES OF CENTER WITH ORIGO AT UPPER
C     LEFT CORNER, COUNT(1,1).
C     BASED ON SCENT.FOR, BUT LEFT AND RIGHT SIDE IS SEPARATED
C     IN RSIG AND RAVRA.
C
C     TOR G. STRAND 970909-970924.
C     REMOVAL COARSE ERRORS ADDED TOR G. STRAND 980316.
C     TOR G. STRAND 001214.
C     SCENTC MODIFIED SCENTB. SETS ALL APPLICABLE PIXELS TO THE
C     S - INTERVAL. TOR G. STRAND 050310.	 
C
CCCCCC
C
C
      DIMENSION COUNT(JMAMA,IMAMA), RAVRA(*),RSIG(*),NORI(*),
     +     RAVTEM(2000),RUNI(2000) 
C
      PI = 3.141592654
C
C      IRTOT = 1.001 + (2.0*RMAX)/DR
      IRTOT = 1.001 + (2.0*SMAX)/DELTAS
      DO I = 1,IRTOT
         NORI(I)  = 0
         RAVRA(I) = 0.0
         RSIG(I)  = 0.0
         RUNI(I)  = 0.0
      ENDDO
      NOTOT  = 0
      NOECOA = 0
      TANA = TAN(2.0*3.141592*ANGLE/360.0)
C
C
C     LOOP OVER COUNT, FIRST RAVRA, SETTING NORI():
C
      IF (XMAX.NE.0.0 .AND. YMAX.NE.0.0) THEN 
         DO I = 1,IMAX
            XIX = FLOAT(I-1)*DXLEN - XNULL
            IF(XIX.LT.-XMAX .OR. XIX.GT.XMAX) THEN
               GO TO 110 
            ENDIF
            DO J = 1,LINJER
               YJY = FLOAT(J-1)*AVSTAN - YNULL
               IF (YJY.LT.-YMAX .OR. YJY.GT.YMAX) THEN
               GO TO 100
               ENDIF
               RIJ = SQRT(XIX**2 + YJY**2)
               TEMP = ATAN(RIJ/CADIST)
               SIJ = 4.0*PI*SIN(0.5*TEMP)/WAVLE
               ITEMP = 1.5 + SIJ/DELTAS
               SIJ = (ITEMP-1)*DELTAS
               IF (SIJ.GT.SMAX .OR. SIJ.LT.SMIN) THEN
                  GO TO 100
               ENDIF  
               IF (XIX .LT. 0.0) THEN
                 ISIJ = 1.001 + (SMAX-SIJ)/DELTAS
               ELSE
                 ISIJ = 1.001 + (SMAX+SIJ)/DELTAS
               ENDIF
               NORI(ISIJ) = NORI(ISIJ) + 1
               RAVRA(ISIJ) = RAVRA(ISIJ) + COUNT(J,I)
               NOTOT = NOTOT + 1
  100          CONTINUE
            ENDDO
  110       CONTINUE
         ENDDO
C
      ELSE IF (XMAX.EQ.0.0 .AND. ANGLE.NE.0.0) THEN
         DO I = 1,IMAX
            XIX = FLOAT(I-1)*DXLEN - XNULL
            DO J = 1,LINJER
               YJY = FLOAT(J-1)*AVSTAN - YNULL
               TEMP = ABS(YJY/XIX)
               RIJ = SQRT(XIX**2 + YJY**2)
               IF (TEMP.GT.TANA .OR. RIJ.LT.RMIN
     +              .OR. RIJ.GT.RMAX .OR. ABS(YJY).GE.YMAX) THEN
               GO TO 101
               ENDIF
               TEMP = ATAN(RIJ/CADIST)
               SIJ = 4.0*PI*SIN(0.5*TEMP)/WAVLE
               ITEMP = 1.5 + SIJ/DELTAS
               SIJ = (ITEMP-1)*DELTAS
               IF (SIJ.GT.SMAX .OR. SIJ.LT.SMIN) THEN
                  GO TO 101
               ENDIF  
               IF (XIX .LT. 0.0) THEN
                 ISIJ = 1.001 + (SMAX-SIJ)/DELTAS
               ELSE
                 ISIJ = 1.001 + (SMAX+SIJ)/DELTAS
               ENDIF
               NORI(ISIJ) = NORI(ISIJ) + 1
               RAVRA(ISIJ) = RAVRA(ISIJ) + COUNT(J,I)
               NOTOT = NOTOT + 1
  101          CONTINUE
            ENDDO
         ENDDO
      ELSE IF (YMAX.EQ.0.0 .AND. ANGLE.NE.0.0) THEN
         DO I = 1,IMAX
            XIX = FLOAT(I-1)*DXLEN - XNULL
            DO J = 1,LINJER
               YJY = FLOAT(J-1)*AVSTAN - YNULL
               RIJ = SQRT(XIX**2 + YJY**2)
               TEMP = ABS(XIX/YJY)
               IF (TEMP.GT.TANA .OR. RIJ.LT.RMIN
     +              .OR. RIJ.GT.RMAX .OR. ABS(XIX).GE.XMAX) THEN
               GO TO 103
               ENDIF
               TEMP = ATAN(RIJ/CADIST)
               SIJ = 4.0*PI*SIN(0.5*TEMP)/WAVLE
               ITEMP = 1.5 + SIJ/DELTAS
               SIJ = (ITEMP-1)*DELTAS
               IF (SIJ.GT.SMAX .OR. SIJ.LT.SMIN) THEN
                  GO TO 103
               ENDIF  
               IF (XIX .LT. 0.0) THEN
                 ISIJ = 1.001 + (SMAX-SIJ)/DELTAS
               ELSE
                 ISIJ = 1.001 + (SMAX+SIJ)/DELTAS
               ENDIF
               NORI(ISIJ) = NORI(ISIJ) + 1
               RAVRA(ISIJ) = RAVRA(ISIJ) + COUNT(J,I)
               NOTOT = NOTOT + 1
  103          CONTINUE
            ENDDO
            CONTINUE
         ENDDO
      ELSE
        WRITE(*,'(1X,A)')
     +    'Inconsistent input for XSCAT,YSCAT or ANGLE!'  
      ENDIF
C
C     AVERAGES TO RAVRA(IR):
C
      DO I = 1,IRTOT
         NORIJ = NORI(I)
         IF (NORIJ.GE.1) THEN
            RAVRA(I) = RAVRA(I)/FLOAT(NORIJ)
         ENDIF
      ENDDO
C
C     NEW LOOP OVER COUNT, NOW RSIG:
C
      IF (XMAX.NE.0.0 .AND. YMAX.NE.0.0) THEN 
         DO I = 1,IMAX
            XIX = FLOAT(I-1)*DXLEN - XNULL
            IF(XIX.LT.-XMAX .OR. XIX.GT.XMAX) THEN
            GO TO 310 
            ENDIF
            DO J = 1,LINJER
               YJY = FLOAT(J-1)*AVSTAN - YNULL
               IF (YJY.LT.-YMAX .OR. YJY.GT.YMAX) THEN
               GO TO 300
               ENDIF
               RIJ = SQRT(XIX**2 + YJY**2)
               TEMP = ATAN(RIJ/CADIST)
               SIJ = 4.0*PI*SIN(0.5*TEMP)/WAVLE
               ITEMP = 1.5 + SIJ/DELTAS
               SIJ = (ITEMP-1)*DELTAS
               IF (SIJ.GT.SMAX .OR. SIJ.LT.SMIN) THEN
                  GO TO 300
               ENDIF
               IF (XIX .LT. 0.0) THEN
                  ISIJ = 1.001 + (SMAX-SIJ)/DELTAS
               ELSE
                 ISIJ = 1.001 + (SMAX+SIJ)/DELTAS              
               ENDIF
               RSIG(ISIJ) = RSIG(ISIJ) + 
     +                   (RAVRA(ISIJ) - COUNT(J,I))**2
               RUNI(ISIJ) = RUNI(ISIJ) +
     +                ABS(RAVRA(ISIJ) - COUNT(J,I))
  300          CONTINUE
            ENDDO
  310       CONTINUE
         ENDDO
C
      ELSE IF (XMAX.EQ.0.0 .AND. ANGLE.NE.0.0) THEN
         DO I = 1,IMAX
            XIX = FLOAT(I-1)*DXLEN - XNULL
            DO J = 1,LINJER
               YJY = FLOAT(J-1)*AVSTAN - YNULL
               TEMP = ABS(YJY/XIX)
               RIJ = SQRT(XIX**2 + YJY**2)
               IF (TEMP.GT.TANA .OR. RIJ.LT.RMIN
     +              .OR. RIJ.GT.RMAX .OR. ABS(YJY).GE.YMAX) THEN
               GO TO 301
               ENDIF
               TEMP = ATAN(RIJ/CADIST)
               SIJ = 4.0*PI*SIN(0.5*TEMP)/WAVLE
               ITEMP = 1.5 + SIJ/DELTAS
               SIJ = (ITEMP-1)*DELTAS
               IF (SIJ.GT.SMAX .OR. SIJ.LT.SMIN) THEN
                  GO TO 301
               ENDIF  
               IF (XIX .LT. 0.0) THEN
                 ISIJ = 1.001 + (SMAX-SIJ)/DELTAS
               ELSE
                 ISIJ = 1.001 + (SMAX+SIJ)/DELTAS
               ENDIF
               RSIG(ISIJ) = RSIG(ISIJ) + 
     +                   (RAVRA(ISIJ) - COUNT(J,I))**2
               RUNI(ISIJ) = RUNI(ISIJ) +
     +                ABS(RAVRA(ISIJ) - COUNT(J,I))
  301          CONTINUE
            ENDDO
         ENDDO
      ELSE IF (YMAX.EQ.0.0 .AND. ANGLE.NE.0.0) THEN
         DO I = 1,IMAX
            XIX = FLOAT(I-1)*DXLEN - XNULL
            DO J = 1,LINJER
               YJY = FLOAT(J-1)*AVSTAN - YNULL
               RIJ = SQRT(XIX**2 + YJY**2)
               TEMP = ABS(XIX/YJY)
               IF (TEMP.GT.TANA .OR. RIJ.LT.RMIN
     +              .OR. RIJ.GT.RMAX .OR. ABS(XIX).GE.XMAX) THEN
               GO TO 303
               ENDIF
               TEMP = ATAN(RIJ/CADIST)
               SIJ = 4.0*PI*SIN(0.5*TEMP)/WAVLE
               ITEMP = 1.5 + SIJ/DELTAS
               SIJ = (ITEMP-1)*DELTAS
               IF (SIJ.GT.SMAX .OR. SIJ.LT.SMIN) THEN
                  GO TO 303
               ENDIF  
               IF (XIX .LT. 0.0) THEN
                 ISIJ = 1.001 + (SMAX-SIJ)/DELTAS
               ELSE
                 ISIJ = 1.001 + (SMAX+SIJ)/DELTAS
               ENDIF
               RSIG(ISIJ) = RSIG(ISIJ) + 
     +                   (RAVRA(ISIJ) - COUNT(J,I))**2
               RUNI(ISIJ) = RUNI(ISIJ) +
     +                ABS(RAVRA(ISIJ) - COUNT(J,I))

  303          CONTINUE
            ENDDO
         ENDDO
      ELSE
        WRITE(*,'(1X,A)')
     +    'Inconsistent input for XSCAT,YSCAT or ANGLE!'  
      ENDIF
C
C     AND STANDARD DEVIATIONS TO RSIG(IR) AND R-FACTOR TO RUNI:
C
      RUNAV = 0.0
      DO I = 1,IRTOT
         NORIJ = NORI(I)
         IF (NORIJ.GE.1) THEN
            RSIG(I) = SQRT(RSIG(I)/FLOAT(NORIJ))
            RUNI(I) = 100.0*RUNI(I)/(FLOAT(NORIJ)*RAVRA(I))
            RUNAV = RUNAV + RUNI(I)
         ENDIF
      ENDDO
      RUNAV = RUNAV/FLOAT(IRTOT)
C
C
      IF (IRECOA.EQ.1) THEN
C
         DO I = 1,IRTOT
            RAVTEM(I) = RAVRA(I)
            NORI(I)  = 0
            RAVRA(I) = 0.0
         ENDDO
         NOTOT  =  0
         NOECOA = 0
C
C     NEW LOOP OVER COUNT, NOW RSIG:
C
      IF (XMAX.NE.0.0 .AND. YMAX.NE.0.0) THEN
         DO I = 1,IMAX
            XIX = FLOAT(I-1)*DXLEN - XNULL
            IF(XIX.LT.-XMAX .OR. XIX.GT.XMAX) THEN
            GO TO 510 
            ENDIF
            DO J = 1,LINJER
               YJY = FLOAT(J-1)*AVSTAN - YNULL
               IF (YJY.LT.-YMAX .OR. YJY.GT.YMAX) THEN
               GO TO 500
               ENDIF
               RIJ = SQRT(XIX**2 + YJY**2)
               TEMP = ATAN(RIJ/CADIST)
               SIJ = 4.0*PI*SIN(0.5*TEMP)/WAVLE
               ITEMP = 1.5 + SIJ/DELTAS
               SIJ = (ITEMP-1)*DELTAS
               IF (SIJ.GT.SMAX .OR. SIJ.LT.SMIN) THEN
                  GO TO 500
               ENDIF  
               IF (XIX .LT. 0.0) THEN
                 ISIJ = 1.001 + (SMAX-SIJ)/DELTAS
               ELSE
                 ISIJ = 1.001 + (SMAX+SIJ)/DELTAS
               ENDIF
               TEMP = COUNT(J,I)
               IF (ABS(TEMP-RAVTEM(ISIJ)).GT.FACOA*RSIG(ISIJ)) THEN
                  NOECOA = NOECOA + 1
                  GO TO 500
               ELSE
                  NORI(ISIJ) = NORI(ISIJ) + 1
                  RAVRA(ISIJ) = RAVRA(ISIJ) + TEMP
                  NOTOT = NOTOT + 1
               ENDIF
  500          CONTINUE
            ENDDO
  510       CONTINUE
         ENDDO
C
      ELSE IF (XMAX.EQ.0.0 .AND. ANGLE.NE.0.0) THEN
         DO I = 1,IMAX
            XIX = FLOAT(I-1)*DXLEN - XNULL
            DO J = 1,LINJER
               YJY = FLOAT(J-1)*AVSTAN - YNULL
               TEMP = ABS(YJY/XIX)
               RIJ = SQRT(XIX**2 + YJY**2)
               IF (TEMP.GT.TANA .OR. RIJ.LT.RMIN
     +              .OR. RIJ.GT.RMAX .OR. ABS(YJY).GE.YMAX) THEN
               GO TO 501
               ENDIF
               TEMP = ATAN(RIJ/CADIST)
               SIJ = 4.0*PI*SIN(0.5*TEMP)/WAVLE
               ITEMP = 1.5 + SIJ/DELTAS
               SIJ = (ITEMP-1)*DELTAS
               IF (SIJ.GT.SMAX .OR. SIJ.LT.SMIN) THEN
                  GO TO 501
               ENDIF  
               IF (XIX .LT. 0.0) THEN
                 ISIJ = 1.001 + (SMAX-SIJ)/DELTAS
               ELSE
                 ISIJ = 1.001 + (SMAX+SIJ)/DELTAS
               ENDIF
               TEMP = COUNT(J,I)
               IF (ABS(TEMP-RAVTEM(ISIJ)).GT.FACOA*RSIG(ISIJ)) THEN
                  NOECOA = NOECOA + 1
                  GO TO 501
               ELSE
                  NORI(ISIJ) = NORI(ISIJ) + 1
                  RAVRA(ISIJ) = RAVRA(ISIJ) + TEMP
                  NOTOT = NOTOT + 1
               ENDIF
  501          CONTINUE
            ENDDO
         ENDDO
      ELSE IF (YMAX.EQ.0.0 .AND. ANGLE.NE.0.0) THEN
         DO I = 1,IMAX
            XIX = FLOAT(I-1)*DXLEN - XNULL
            DO J = 1,LINJER
               YJY = FLOAT(J-1)*AVSTAN - YNULL
               RIJ = SQRT(XIX**2 + YJY**2)
               TEMP = ABS(XIX/YJY)
               IF (TEMP.GT.TANA .OR. RIJ.LT.RMIN
     +              .OR. RIJ.GT.RMAX .OR. ABS(XIX).GE.XMAX) THEN
               GO TO 503
               ENDIF
               TEMP = ATAN(RIJ/CADIST)
               SIJ = 4.0*PI*SIN(0.5*TEMP)/WAVLE
               ITEMP = 1.5 + SIJ/DELTAS
               SIJ = (ITEMP-1)*DELTAS
               IF (SIJ.GT.SMAX .OR. SIJ.LT.SMIN) THEN
                  GO TO 503
               ENDIF  
               IF (XIX .LT. 0.0) THEN
                 ISIJ = 1.001 + (SMAX-SIJ)/DELTAS
               ELSE
                 ISIJ = 1.001 + (SMAX+SIJ)/DELTAS
               ENDIF
               TEMP = COUNT(J,I)
               IF (ABS(TEMP-RAVTEM(ISIJ)).GT.FACOA*RSIG(ISIJ)) THEN
                  NOECOA = NOECOA + 1
                  GO TO 503
               ELSE
                  NORI(ISIJ) = NORI(ISIJ) + 1
                  RAVRA(ISIJ) = RAVRA(ISIJ) + TEMP
                  NOTOT = NOTOT + 1
               ENDIF
  503          CONTINUE
            ENDDO
         ENDDO
C
      ELSE
        WRITE(*,'(1X,A)')
     +    'Inconsistent input for XSCAT,YSCAT or ANGLE!'  
      ENDIF
C
C        AVERAGES TO RAVRA(IR):
C
         DO I = 1,IRTOT
            NORIJ = NORI(I)
            IF (NORIJ.GE.1) THEN
               RAVRA(I) = RAVRA(I)/FLOAT(NORIJ)
            ENDIF
         ENDDO
      ENDIF
C
C  999 CONTINUE
C
      RETURN
      END
      