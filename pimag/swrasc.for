      SUBROUTINE SWRASC(JMAMA,IMAMA,XMAXT,YMAXT,
     +    ODEN,IXMA,JYMA,XNULL,YNULL,XRES,YRES,R)
C
C     USES SUBROUTINE SORT2.FOR
C
C     COMPUTES AND FILES MIDDLE LINE, MIDDLE COLUMN AND THE VALUES
C     AT THE DISTANCE R FROM THE CENTER (XNULL, YNULL), WITHIN THE
C     PIXEL SIZE AS FUNCTION OF INCREASING ANGLES.
C
      PARAMETER (IFIL = 5)
C
      DIMENSION ODEN(JMAMA,IMAMA),VALUE(10000),XVAL(10000),YVAL(10000),
     +           ANGLE(10000)
C
      IXNULL = 1.001 + XNULL/XRES
      JYNULL = 1.001 + YNULL/YRES
C
C     WRITING MIDDEL LINE AND MIDDEL COLUMN:
C
      OPEN(IFIL,FILE='COLUM.TXT',ACCESS='SEQUENTIAL')
      REWIND(IFIL)
      DO J = 1,JYMA
         WRITE(IFIL,'(1X,I5,2X,E13.7)') J,ODEN(J,IXNULL) 
      ENDDO
      CLOSE (IFIL)
      OPEN(IFIL,FILE='LINE.TXT',ACCESS='SEQUENTIAL')
      REWIND(IFIL)
      DO I = 1,IXMA
         WRITE(IFIL,'(1X,I5,2X,E13.7)') I,ODEN(JYNULL,I) 
      ENDDO
      CLOSE (IFIL)
C
      NOVAL = 0
      DO JYJ = 1,JYMA
         YJ = FLOAT(JYJ-1)*YRES - YNULL
         DO IXI = 1,IXMA
            XI = FLOAT(IXI-1)*XRES - XNULL
            IF (ABS(YJ).GT.YMAXT .OR. ABS(XI).GT.XMAXT) THEN
               GO TO 999 
            ENDIF
            RIJ = SQRT(XI**2 + YJ**2)
            IF (RIJ.GE.(R-XRES/2.0) .AND. RIJ.LE.(R+XRES/2.0)) THEN
               NOVAL = NOVAL + 1
               VALUE(NOVAL) = ODEN(JYJ,IXI)
               XVAL(NOVAL) = XI
               YVAL(NOVAL) = YJ
            ENDIF
  999       CONTINUE
         ENDDO
      ENDDO 
C
      WRITE (*,*)NOVAL
      RADE = 360.0/(2.0*3.141592654)
      DO I = 1,NOVAL
         ANGLE(I) = RADE*ASIN(ABS(YVAL(I))/SQRT(XVAL(I)**2+YVAL(I)**2))
         IF(XVAL(I).LT.0.0 .AND. YVAL(I).GT.0.0) THEN
            ANGLE(I) = 180.0 - ANGLE(I) 
         ELSE IF(XVAL(I).LT.0.0 .AND. YVAL(I).LT.0.0) THEN
            ANGLE(I) = ANGLE(I) + 180.0
         ELSE IF(XVAL(I).GT.0.0 .AND. YVAL(I).LT.0.0) THEN
            ANGLE(I) = 360.0 - ANGLE(I)
         ENDIF
      ENDDO
      CALL SORT2(NOVAL,ANGLE,VALUE)
      OPEN(IFIL,FILE='RADI.TXT',ACCESS='SEQUENTIAL')
      DO I = 1,NOVAL
        WRITE(IFIL,'(1X,F10.5,E15.5)')
     +       ANGLE(I),VALUE(I)
      ENDDO
      WRITE(IFIL,'(1X,I10,A,F10.5)')
     +         NOVAL,' noval values at the distance ',R
      CLOSE(IFIL)
C
C
      RETURN
      END
      