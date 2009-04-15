      SUBROUTINE SMIDPA(DELLEN,COUNT,RMIN,RMAX,SENNEW)
C
C     SMIDPOQ:\GEDDOS\EXE
C     LAST REVISION 890426, TOR G. STRAND.
C
C     OUTPUT TO SCREEN REMOVED IN SMIDPA FOR PJLB.
C
C     TOR G. STRAND 941115.     
C
C     RETURNS NEW VALUE FOR CENTRE OF PLATE, SENNEW:
C
      DIMENSION COUNT(*), SQDI(7), RASQ(7)
C
      CHARACTER ANSW*1
C
C
      ISTEP = 3
      NOIT = 0
      SENLEN = RMAX
      SENNEW = SENLEN
C
C     KEEPING THE SAME RANGE OVER RIGHT SIDE OF PLATE IN LATER LOOPS,
C     REDUCING INTERVALS BY 20% DUE TO TERMINATION ERRORS IN SMOOFT:
C
      TEMP = (RMAX - RMIN)/10.0
      ISTAR = 1.001 + (SENLEN + RMIN+TEMP)/DELLEN
      IEND  = 1.001 + (SENLEN + RMAX-TEMP)/DELLEN
C
C     AND THEN STARTING ITERATION:
C
  100 CONTINUE
C
      IMID = 1.001 + SENNEW/DELLEN
      NOIT = NOIT + 1
      IF (NOIT.GT.20) THEN
         WRITE(*,'(1X,A)') 'Unable to calculate improved centre of'
         WRITE(*,'(1X,A)') 'pattern. Measured value used!!'
         SENNEW = SENLEN
         GO TO 200
      ENDIF
C
C
      DO 110 K = 1,3
         SQDI(K) = 0.0
         SENK = SENNEW + FLOAT((K - 2)*ISTEP)*DELLEN
         DO 120 I = ISTAR,IEND
            J = 1.001 + (SENK -(FLOAT(I-1)*DELLEN -SENK))/DELLEN
C        SECOND DERIVATIVES:
C           SQDI(K) = SQDI(K)+   (COUNT(I) - 2*COUNT(I+1) + COUNT(I+2)
C    +                           -COUNT(J) + 2*COUNT(J-1) - COUNT(J-2))
C    +                                            **2
C        FIRST DERIVATIVES:
C           SQDI(K) = SQDI(K) + (COUNT(I) - COUNT(I+1)
C    +                          -COUNT(J) + COUNT(J-1))**2
C     FIRST DERIVATIVES, ABSOLUTE VALUES:
            SQDI(K) = SQDI(K) + ABS(COUNT(I-1) - COUNT(I+1)
     +                             -COUNT(J+1) + COUNT(J-1))
C     ONLY L. SQ.'S AGREEMENT:
C           SQDI(K) = SQDI(K) + (COUNT(I) - COUNT(J))**2
  120    CONTINUE
         SQDI(K) = SQDI(K)/FLOAT(IEND-ISTAR)
  110 CONTINUE
C
C
      IF (SQDI(2).LT.SQDI(1) .AND. SQDI(2).LT.SQDI(3)) THEN
         ISTEP = 1
C
         DO 210 K = 1,7
            SQDI(K) = 0.0
            RASQ(K) = SENNEW + FLOAT((K - 4)*ISTEP)*DELLEN
            DO 220 I = ISTAR,IEND
               J = 1.001 + (RASQ(K) -(FLOAT(I-1)*DELLEN -RASQ(K)))
     +            /DELLEN
C     SECOND DERIVATIVES:
C              SQDI(K) = SQDI(K)+ (COUNT(I) - 2*COUNT(I+1) + COUNT(I+2)
C    +                            -COUNT(J) + 2*COUNT(J-1) - COUNT(J-2))
C    +                                            **2
C     FIRST DERIVATIVES:
C              SQDI(K) = SQDI(K) + (COUNT(I) - COUNT(I+1)
C    +                             -COUNT(J) + COUNT(J-1))**2 
C     FIRST DERIVATIVES, ABSOLUTE VALUES:
               SQDI(K) = SQDI(K) + ABS(COUNT(I-1) - COUNT(I+1)
     +                                -COUNT(J+1) + COUNT(J-1))
C     ONLY L. SQ.'S AGREEMENT:
C              SQDI(K) = SQDI(K) + (COUNT(I) - COUNT(J))**2
  220       CONTINUE
  210    CONTINUE
C
         SQMIN = SQDI(1)
         K = 1
         DO 230 I = 2,6
            IF (SQDI(I).LT.SQMIN) THEN
               SQMIN = SQDI(I)
               K = I
            ENDIF
  230    CONTINUE
C        MIN OF Y= AA*X**2 + BB*X + CC THROUGH SQDI(1)..SQDI(3):
         X1 = RASQ(K-1)
         X2 = RASQ(K)
         X3 = RASQ(K+1)
         X3X1 = X3 - X1
         X3X2 = X3 - X2
         X3X12 = X3**2 - X1**2
         X3X22 = X3**2 - X2**2
         AA = (X3X1*(SQDI(K+1)-SQDI(K))-X3X2*(SQDI(K+1)-SQDI(K-1)))
     +      /(X3X1*X3X22 - X3X2*X3X12)
         BB = (SQDI(K+1) - SQDI(K-1) - AA*X3X12)/X3X1
         SENNEW = -0.50*BB/AA
C
C
      GO TO 200
      ELSE IF (SQDI(1).GT.SQDI(2) .AND. SQDI(2).GT.SQDI(3)) THEN
         SENNEW = SENNEW + FLOAT(ISTEP)*DELLEN
      GO TO 100
      ELSE IF (SQDI(1).LT.SQDI(2) .AND. SQDI(2).LT.SQDI(3)) THEN
         SENNEW = SENNEW - FLOAT(ISTEP)*DELLEN
      GO TO 100
      ELSE
         ISTEP = ISTEP + 1
      GO TO 100
      ENDIF
  200 CONTINUE
C
C
      RETURN
      END
