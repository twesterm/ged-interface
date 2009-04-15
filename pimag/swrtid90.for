      SUBROUTINE SWRTID90(IOUT)
C
C     WRITES TIME AND DATE TO FILE IOUT:
C
C     LAST REVISION 880711, TOR G. STRAND.
C     REVISED SWRTID 030603 FOR fORTRAN90, TGS.
C
      CHARACTER(12)REAL_CLOCK(3)
      CHARACTER MON*4, MONAR*4
C
C
      INTEGER DATE_TIME(8)
      INTEGER*2 IHR, IMIN, ISEC, I100TH, IYR, IMON, IDAY
C
C
      DIMENSION MONAR(12)
C
      DATA MONAR/'Jan.','Feb.','Mar.','Apr.',' May','June','July',
     +'Aug.','Sep.','Oct.','Nov.','Dec.'/
C
C
      CALL DATE_AND_TIME (REAL_CLOCK(1),REAL_CLOCK(2),REAL_CLOCK(3),
     + DATE_TIME)
C
      IYR  = DATE_TIME(1)
      IMON = DATE_TIME(2)
      IDAY = DATE_TIME(3)
      IHR  = DATE_TIME(5)
      IMIN = DATE_TIME(6)
C
C      WRITE (*,*) IYR
C      WRITE (*,*) IDAY,IMON
C      WRITE (*,*) IHR,IMIN
C
      DO 100 I = 1,12
         IF (IMON.EQ.I) THEN
            MON = MONAR(I)
         ENDIF
  100 CONTINUE
C
      WRITE(IOUT,'(57X,A4,1X,I2,A,I4,A)') MON,IDAY,'., ',IYR,'.'
C
      IF (IHR.LT.10 .AND. IMIN.LT.10) THEN
         WRITE(IOUT,'(66X,A,I1,A,I1,A)') '0',IHR,':0',IMIN,'.'
      ELSE IF (IHR.GE.10 .AND. IMIN.LT.10) THEN
         WRITE(IOUT,'(66X,I2,A,I1,A)') IHR,':0',IMIN,'.'
      ELSE IF (IHR.LT.10 .AND. IMIN.GE.10) THEN
         WRITE(IOUT,'(66X,A,I1,A,I2,A)') '0',IHR,':',IMIN,'.'
      ELSE
         WRITE(IOUT,'(66X,I2,A,I2,A)') IHR,':',IMIN,'.'
      ENDIF
C
      RETURN
      END
