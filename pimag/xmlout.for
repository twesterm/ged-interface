C     RJF
C     Output of reduced+sectorcorr. scattering data, I(s) 
C     in new Ed@ed .xml  format 
      
      SUBROUTINE XMLOUT(S,OPP1,NOS,IPLA,SMIN,SMAX,DELTAS,WAVLE,CADIST,
     +                  ISECT, CURVEFILE)
      
      DIMENSION S(NOS)
      DIMENSION OPP1(10,400)
      CHARACTER*100 OUTFILE 
      character(*) curvefile
      INTEGER NMIN,NMAX
      

      NMIN = SMIN/DELTAS + 0.00001
      NMAX = SMAX/DELTAS + 0.00001

      OPEN(UNIT=21,FILE=curvefile,FORM='FORMATTED',STATUS='UNKNOWN')
      
      IF (IPLA.EQ.1)THEN
         WRITE(21,*) '1  5'
         WRITE(21,'(I3)') IPLA
         WRITE(21,'(3F10.5,2I4)')
     +        WAVLE,CADIST,DELTAS,NMIN,NMAX
         DO I = 1,NOS
            WRITE(21,'(21(F12.5))')
     +           OPP1(1,I)/10000.0
         ENDDO
      ELSE
         WRITE(IOUT,'(/1X,A)')
     +         'Too many Plates for XMLOUT.FOR'
      ENDIF

c      WRITE(IOUT,'(/1X,A,A11,A)')'Result on ',curvefile,'.'

      END



C     For more plates, something like that should be done:
C
C         READ(IFIL,'(1X,2I5,4F10.5,F10.7,I5)')
C     +           NOPLA,NOS,SMIN,SMAX,DELTAS,CADIST,WAVLE,ISECT
C         DO I = 1,NOS
C            READ(IFIL,'(21(1X,E16.7))')
C     +                S(I),(OPP(J,I),J=1,2*(IPLA-1))
C         ENDDO
C         REWIND(IFIL)
C         WRITE(IFIL,'(1X,2I5,4F10.5,F10.7,I5)')
C     +           IPLA,NOS,SMIN,SMAX,DELTAS,CADIST,WAVLE,ISECT
C         DO I = 1,NOS
C            WRITE(IFIL,'(21(1X,E16.7))')
C     +                S(I),(OPP(J,I),J=1,2*IPLA)
C         ENDDO
C      ENDIF   



