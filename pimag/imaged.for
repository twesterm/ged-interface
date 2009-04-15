      PROGRAM PIMAGA
C
C     Tor G. Strand 010514.
C     Kirsten Aarset 170701     
c     Kirsten Aarset 230404

C     READS ONE 16 BITS *.IMG FILE FROM THE FUIJ IMAGE SCANNER.
C     REFINES CENTER COORDINATES FROM INPUT PIXEL VALUES OF CENTER.
C     TRANSFERS TO S-SCALE, DOES SECTOR- AND PLANAR-PLATE-CORRECTIONS.
C     MULTIPLIES BY S**4. SAVES average of LEFT AND RIGHT SIDES.
C
C     INPUT FROM *.inp (SEE EXAMPLE) AND *.IMG.
c*******************************************************************************
c Example for  *.inp
c        2   
c r010611.img                           (A7)    The image file -  max 7 letters/numbers
c 4000 3000                            (2I5)    The size of the scan  (IXMA,JYMA) - x and y
c 1766 1734                            (2I5)    The approx. center in pixel - x og y. 
c 248.83    0.0585600   0.25           (3F10.5) Cameradist (mm), wavelength, delta
c r010613.img                           (A7)    The image file -  max 7 letters/numbers
c 4000 3000                            (2I5)    The size of the scan  (IXMA,JYMA) - x and y
c 1766 1734                            (2I5)    The approx. center in pixel - x og y. 
c 248.83    0.0585600   0.25           (3F10.5) Cameradist (mm), wavelength, delta.

C************************************************************************************
C
C 010219: ADDED ANGLE TO INPUT LINE XSCAT AND YSCAT. IF ANGLE = 0.0,
C         XSCAT AND YSCAT mm IS THE AREA OF THE PLATE APPLIED.
C         IF XSCAT = 0.0 AND YSCAT AND ANGLE GT 0.0 THE SECTORS
C         OF OPENING ANGLE 2.0*ANGLE SYMMETRICALLY AROUND THE X-AXIS ARE
C         APPLIED. CORRESPONDINGLY FOR YSCAT=0.0,XSCAT AND ANGLE BOTH GT 0.0.
C 010301: RE-INSERTED XPIXFA AND YPIXFA FOR PIXEL SCALING.
C  
c 230404 Changed the format of the output (same as Edinburgh) PS! The inputfile has also changed

C     ************************************************************
C     SUBROUTINES SWRTID,SCENT,SMOOFT(REALFT(FOUR1)),SMIDPA,
C     SCENT2, AND SWRASC(SORT2) ARE ON IMAGERED.LIB.
C     ************************************************************
C
      INTEGER*1 IBYTE1,IBYTE2
C
      PARAMETER ( IESE=8, IFIL=9, IOUT=10, IAGF=11)
      PARAMETER (ICHA=9 ,IAMAX=10)
C     USUALLY:
C      PARAMETER (JMAMA=3001, IMAMA=4001)
C     lONG AXIS Y:
      PARAMETER (JMAMA=4501, IMAMA=4001)     
      PARAMETER (IPAMA=10, MA=5)
      PARAMETER (NOMA=50)
C
      CHARACTER CHANO*1, CHASE*1, SECFI*18, BIN*4, ISEC*13
      CHARACTER FINAME*12
C      
      CHARACTER*12 filename, filename2

      DIMENSION CHANO(ICHA)
      DIMENSION ODEN(JMAMA,IMAMA)
      DIMENSION RSIG(2000),RAVRA(2000),NORI(2000)
      DIMENSION RAVY(2000), RAVX(2000), RSCA(2000), TEMPA(1024),
     +                                              TEMPB(1024)
      DIMENSION S(400), ONS(2,400), OPP(20,400)
      DIMENSION SECTOR(2000), SL(400),opp_ave(400)
      real*8 opp_ave
      CHARACTER*100 outfile 

      DATA CHANO/'1','2','3','4','5','6','7','8','9'/
      DATA PI/3.141592654/ BIN/'.BIN'/ ISEC/'C:\edprog\ISECT'/
C
C     OPENING AND READING PIMAG.TXT.
C     
c     Write/read to the screen 
      write(*,*)'Name of input file (*.inp)'
      read(*,"(A12)")filename                   
c
      OPEN(16,file=filename,status='old')
      read(16,"(I4)")no_plates               !total number of plates
      
      Do 678 k=1,no_plates
      read(16,"(a12)")filename2 
      READ(16,'(2I5)')IXMA,JYMA 
      READ(16,'(2I5)')IXCEN,JYCEN
      READ(16,'(3F10.5)')CADIST,WAVLE,DELTAS
c******************************************************************************
c     Different constants
      IPLA =1                     !Should always be 1 
      PIXEL=0.050                 !PIXEL, pixel mm.
      XPIXFA=1.0                  !Scaling of pixel i x-direction
      YPIXFA=0.99013              !Scaling of pixel i y-direction
      XSCAT=152.0                 !XSCAT 
      YSCAT=110.0                 !YSCAT Angel of plate that is used
      ANGLE=0.0                   !
      rmin=25.0                   !Part of plate that is used to find the center in mm
      rmax=55.0                   !Part of plate that is used to find the center in mm
      dr= 0.10                    !Delta used in finding the center in mm.
      rmint=10.5                  !R-min for final data in mm
      rmaxt=74.0                  !R-max for final data in mm
      drt=0.20                    !Delta used for final result mm.
      IRECOA=1                    !IRECOA=(1/0,rem./rem.not)coarse error
      TUNEXP=0.0                  !TUNEXP value set in middel.
      RADI=25.0                   !RADI, points at RADI printet .NE.0.0.
c      SEPLA=20.649        ! sector-to-film distanse for Reading   
c      SEPLA=21.334        ! sector-to-film distanse for Reading   
      SEPLA=20.625        ! sector-to-film distanse for Reading   
      ISECT=9             ! Reading sector : isect9.bin.
c************************************************************************
      FINAME = filename2
C
      WRITE(*,'(/1X,A/)') '*** Imagered ***'
      OPEN(IOUT,FILE='OUT.TXT',ACCESS='SEQUENTIAL')
      REWIND IOUT
      CALL SWRTID(IOUT)
      WRITE(IOUT,'(1X,A/)') '*** PIMAGA of 010514, Tor G.Strand ***'
      WRITE(IOUT,'(1X,A,A12,A,I2)')
     +    'File ',FINAME,' was processed for plate',IPLA
      WRITE(IOUT,'(/1X,A,I5,A,I5,A)')
     +   'IXMA = ',IXMA,' and JYMA = ',JYMA,' are max x and y of scan.'
C     Raphael , zwischen A und ) entfernt:
      WRITE(IOUT,'(1X,A,F10.5,A)')
     +                     'PIXEL = ',PIXEL, ' /mm.'
      WRITE(IOUT,'(1X,A,F8.5,A,F8.5)')
     +        'To scale: XPIXFA = ',XPIXFA,' YPIXFA = ',YPIXFA 
      WRITE(IOUT,'(1X,A,F6.1,A,F6.1,A)')
     +     'XSCAT = ',XSCAT,'  and YSCAT = ',YSCAT,
     +     ' are applied x and y size of pattern /mm.'
      WRITE(IOUT,'(1X,A,F6.1,A)')
     +     'ANGLE = ',ANGLE,' is half sector angle, degrees.'
      WRITE(IOUT,'(1X,A,I5,A,I5,A/)')
     +   'IXCEN = ',IXCEN,'  and JYCEN = ',JYCEN,
     +   ' app. indices of pattern center on *.IMG.'
      WRITE(IOUT,'(1X,A)') 'RMIN, RMAX ,DR,to correct center:'
      WRITE(IOUT,'(1X,3F10.5,A/)') RMIN,RMAX,DR,' mm.'
      WRITE(IOUT,'(1X,A)')
     +      'RMIN, RMAX ,DR, XMAXT, YMAXT, for final result:'
      YMAXT = YSCAT/2.0
      XMAXT = XSCAT/2.0
      WRITE(IOUT,'(1X,5F10.5,A)') RMINT,RMAXT,DRT,XMAXT,YMAXT,' mm.'
      WRITE(IOUT,'(1X,A,F10.3,A,/)')
     +           'TUNEXP =',TUNEXP,' value set for unexposed plate.'
      WRITE(IOUT,'(1X,A,F7.2,A,F10.7,A,F6.3,A)')
     +   'Camera dist. ',CADIST,'mm. Wave length ',WAVLE,'AA. Delta s '
     +   ,DELTAS,' AA-1.'
      WRITE(IOUT,'(1X,A,F5.2,A,I2)')
     + 'Sector-to plate ',SEPLA,'mm. Sector correction no. ',ISECT

C     SMIN AND SMAX

      SMIN = 4.0*PI*SIN(0.5*ATAN(RMINT/CADIST))/WAVLE
      SMIN = FLOAT(IFIX((SMIN + DELTAS)/DELTAS))*DELTAS
      SMAX = 4.0*PI*SIN(0.5*ATAN(RMAXT/CADIST))/WAVLE
      SMAX = FLOAT(IFIX((SMAX - DELTAS)/DELTAS))*DELTAS
      WRITE(IOUT,'(/1X,A,F6.3,A,F7.3,A/)')
     +       'SMIN = ',SMIN,' SMAX = ',SMAX,' AA-1'

      IWIDTH = IXMA
      ILENG  = JYMA

      XNULL = FLOAT(IXCEN - 1)*PIXEL*XPIXFA
      YNULL = FLOAT(JYCEN - 1)*PIXEL*YPIXFA

      XNULLO = XNULL
      YNULLO = YNULL

      XRES = PIXEL*XPIXFA
      YRES = PIXEL*YPIXFA


      IWRLC = 0
      OPEN(IFIL,FILE=filename2,ACCESS='SEQUENTIAL',
     +       FORM='BINARY')
      REWIND(IFIL)

      DO JJ = 1,ILENG 
         DO II = 1,IWIDTH
            READ (IFIL) IBYTE1,IBYTE2
            TEMP1 = IBYTE1
            IF (TEMP1.LT.0) THEN
               TEMP1 = TEMP1 + 256.0
            ENDIF
            TEMP2 = IBYTE2
            IF (TEMP2.LT.0) THEN
               TEMP2 = TEMP2 +256.0
            ENDIF
            TEMP  =  256.0*TEMP1 + TEMP2
            ODEN(JJ,II) = TEMP
         ENDDO
      ENDDO
      CLOSE (IFIL)
      WRITE(*,'(1X,A,A12,A)') 'The file ',FINAME,' was read.'

      IF (IWRLC.EQ.1) THEN   
         IXNULL = 1.001 + XNULL/(PIXEL*XPIXFA)
         JYNULL = 1.001 + YNULL/(PIXEL*YPIXFA)

C        WRITING MIDDEL LINE AND MIDDEL COLUMN:

         OPEN(IFIL,FILE='COLUM.TXT',ACCESS='SEQUENTIAL')
         REWIND(IFIL)
         DO J = 1,JYMA
            WRITE(IFIL,'(1X,I5,2X,E13.7)')
     +          J,ODEN(J,IXNULL) 
         ENDDO
         CLOSE (IFIL)
         OPEN(IFIL,FILE='LINE.TXT',ACCESS='SEQUENTIAL')
         REWIND(IFIL)
         DO I = 1,IXMA
            WRITE(IFIL,'(1X,I5,2X,E13.7)')
     +         I,ODEN(JYNULL,I) 
         ENDDO
         CLOSE (IFIL)

         GO TO 999 
      ENDIF 
       
      IF (RMAX.GT.XNULL) THEN
         RMAX = IFIX(XNULL/DR)*DR - 2.0
      ENDIF

      WRITE(IOUT,'(1X,A)')
     +       'Applied RMIN, RMAX ,DR to correct center coordinates:'
      WRITE(IOUT,'(1X,3F10.5,A,/)') RMIN,RMAX,DR,' mm.'
      OUTEND = 0.1*RMAX
      OUTSTA = RMIN + OUTEND
      WRITE(IOUT,'(1X,A)')
     +      'Applied OUTSTA, OUTEND for correcting centers:'
      WRITE(IOUT,'(1X,2F10.5,A)') OUTSTA,OUTEND,' mm.'
      WRITE(*,'(1X,A,F10.5,A,F10.5,A,/)')
     +         'XNULL= ',XNULL,' YNULL = ',YNULL,' mm.'
      WRITE(*,'(1X,A)') 'Changes: '

C     *****************************************************
            ICYCLE = 1
  777       CONTINUE

            CALL SCENT(JMAMA,IMAMA,
     +              IWIDTH,ILENG,ODEN,XRES,YRES,DR,RMIN,
     +              RMAX,XNULL,YNULL,RAVX,RAVY)
            ITEMP1 = 1.001 + (RMAX-RMIN)/DR
            NOR = 1.001 +(2.0*RMAX)/DR
            PTS = 0.03*ITEMP1
            PTS2= 0.40*ITEMP1
            DO I= 1,ITEMP1
               TEMPA(I) = RAVX(I)
               TEMPB(I) = RAVX(I)
            ENDDO
            CALL SMOOFT(TEMPA,ITEMP1,PTS)
            CALL SMOOFT(TEMPB,ITEMP1,PTS2)
            DO I= 1,ITEMP1
               RAVX(I) = TEMPA(I) - TEMPB(I)
            ENDDO
            DO I= 1,ITEMP1
               TEMPA(I) = RAVX(NOR+1-I)
               TEMPB(I) = RAVX(NOR+1-I)
            ENDDO
            CALL SMOOFT(TEMPA,ITEMP1,PTS)
            CALL SMOOFT(TEMPB,ITEMP1,PTS2)
            DO I= 1,ITEMP1
               RAVX(NOR+1-I) = TEMPA(I) - TEMPB(I)
            ENDDO
            DO I= 1,ITEMP1
               TEMPA(I) = RAVY(I)
               TEMPB(I) = RAVY(I)
            ENDDO
            CALL SMOOFT(TEMPA,ITEMP1,PTS)
            CALL SMOOFT(TEMPB,ITEMP1,PTS2)
            DO I= 1,ITEMP1
               RAVY(I) = TEMPA(I) - TEMPB(I)
            ENDDO
            DO I= 1,ITEMP1
               TEMPA(I) = RAVY(NOR+1-I)
               TEMPB(I) = RAVY(NOR+1-I)
            ENDDO
            CALL SMOOFT(TEMPA,ITEMP1,PTS)
            CALL SMOOFT(TEMPB,ITEMP1,PTS2)
            DO I= 1,ITEMP1
               RAVY(NOR+1-I) = TEMPA(I) - TEMPB(I)
            ENDDO
 
            CALL SMIDPA(DR,RMAX,RAVX,OUTSTA,OUTEND,SENX)
            CALL SMIDPA(DR,RMAX,RAVY,OUTSTA,OUTEND,SENY)

            DSENX = SENX - RMAX
            XNUNY = XNULL + DSENX
            DSENY = SENY - RMAX
            WRITE(*,*)DSENX,DSENY
            YNUNY = YNULL + DSENY
            IF (ABS(DSENX).GT.0.05*DR .OR. ABS(DSENY).GT.0.05*DR) THEN
               XNULL = XNUNY
               YNULL = YNUNY
               ICYCLE = ICYCLE +1
               IF (ICYCLE.GE.15) THEN
                  WRITE(IOUT,'(1X,A)')
     +                    'The iteration did not converge!!' 
      write(*,*)'The iteration did not converge!!' 
                  GO TO 778
               ENDIF
               GO TO 777
            ENDIF
C     *********************************************************
  778       CONTINUE
      WRITE(IOUT,'(/1X,A,F7.3,A,F7.3,A)')
     +     'XNULL = ',XNULLO,'  and YNULL = ',YNULLO,
     +     ' are center coordinates in new array /mm.'
            WRITE(IOUT,'(1X,A,I3,A)') 'After ',ICYCLE,' cycles:'
            WRITE(IOUT,'(1X,A)') 'x dir, SENX, DSENX, XNULL, XNUNY:'
            WRITE(IOUT,'(1X,4F10.5,A)') SENX,DSENX,XNULL,XNUNY,' mm.'
            WRITE(IOUT,'(1X,A)') 'y dir, SENY, DSENY, YNULL, YNUNY:'
            WRITE(IOUT,'(1X,4F10.5,A)') SENY,DSENY,YNULL,YNUNY,' mm.'
            XNULL = XNUNY
            YNULL = YNUNY
C
C           AND COLLECTING AND FILING:
C
            CALL SCENT2(IMAMA,JMAMA,
     +              IWIDTH,ILENG,ODEN,XRES,YRES,DRT,RMINT,
     +              RMAXT,XMAXT,YMAXT,ANGLE,XNULL,YNULL,RSIG,
     +              RAVRA,IRECOA,NOTOT,NOECOA,NORI,RUNAV)
C
            IRTOT = 1.001 + (2.0*RMAXT)/DRT
            DO I = 1,IRTOT
               RSCA(I) = -RMAXT + FLOAT(I-1)*DRT
            ENDDO
C
            WRITE(IOUT,'(/1X,A,I7,A)')
     +              'Applied alltogether ',NOTOT,' points.'
            WRITE(IOUT,'(1X,A,I7,A)')
     +              'Removed alltogether ',NOECOA,' coars errors.'
            WRITE(IOUT,'(/1X,A)')
     +         'Average and std."s for grey scale:'
            WRITE(IOUT,'(/1X,A,3X,A)')
     +          '   I   X     N   AVER    STDV   NORI',
     +          '   I   X     N   AVER    STDV   NORI'
            WRITE(IOUT,'(2(1X,I5,F6.1,3X,F8.1,F8.1,I6,1X))')
     +       (I,RSCA(I),RAVRA(I),RSIG(I),NORI(I),
     +                                  I=1,IRTOT,20)

      WRITE(IOUT,'(/1X,A,F7.3,A,/)') 'Average R-factor',RUNAV,'%.'

      ISTART = 2.001 + (RMAXT - RMINT)/DRT
      ISTOP = 0.001 + (RMAXT + RMINT)/DRT
      DO I = ISTART,ISTOP
         RAVRA(I) = TUNEXP
      ENDDO
C     TO S - SCALE:

      FF = 2.0**15
      GG = 2.0**16/5.0

      NOS = 1.001 + (SMAX - SMIN)/DELTAS
      DO I = 1,NOS
         S(I) = SMIN + FLOAT(I-1)*DELTAS
         SL(I) = CADIST*TAN(2.0*ASIN(S(I)*WAVLE/(4.0*PI)))
C        LEFT:
         ILE1 = 1.001 + (RMAXT - SL(I))/DRT
         ILE1 = ILE1 + 1
         RILE1 = RMAXT - FLOAT(ILE1-1)*DRT
         ILE2 = ILE1-1
         RILE2 = RMAXT - FLOAT(ILE2-1)*DRT
         AAA = (RAVRA(ILE2)-RAVRA(ILE1))/(RILE2-RILE1)
         BBB = RAVRA(ILE2) - AAA*RILE2
         ONS(1,I) = AAA*SL(I) + BBB
         TEMP = ONS(1,I)
         ONS(1,I) = 0.25*10.0**((TEMP-FF)/GG)
C        AND RIGHT:
         IRI1 = 1.001 + (RMAXT + SL(I))/DRT
         RRI1 = -RMAXT + FLOAT(IRI1-1)*DRT
         IRI2 = IRI1+1
         RRI2 = -RMAXT + FLOAT(IRI2-1)*DRT
         AAA = (RAVRA(IRI2)-RAVRA(IRI1))/(RRI2-RRI1)
         BBB = RAVRA(IRI2) - AAA*RRI2
         ONS(2,I) = AAA*SL(I) + BBB
         TEMP = ONS(2,I)
         ONS(2,I) = 0.25*10.0**((TEMP-FF)/GG)
      ENDDO

C     SECTOR CORRECTION

      NOFIL = 2*(IPLA-1) + 1
      IF (ISECT.NE.0) THEN
         DO I = 1,9
            IF (I.EQ.ISECT) THEN
               CHASE = CHANO(I)
            ENDIF
         ENDDO
         SECFI = ISEC//CHASE//BIN
         OPEN(IESE,FILE=SECFI,ACCESS='SEQUENTIAL',FORM=
     +         'UNFORMATTED')
         REWIND IESE
         READ(IESE) NOPO,XMIN,XMAX,DX,(SECTOR(I),I=1,NOPO)
         CLOSE(IESE)

         DO I = 1,NOS
            SS = SMIN + FLOAT(I-1)*DELTAS
            TETA = 2.0*ASIN(SS*WAVLE/(4.0*PI))
            DISEC = (CADIST - SEPLA)*TAN(TETA)
            IF (DISEC.LT.XMIN) THEN
               OPP(NOFIL,I) = 0.0
               OPP(NOFIL+1,I) = 0.0
               GO TO 887
            ENDIF
            IF (DISEC.GT.XMAX) THEN
               OPP(NOFIL,I) = 0.0
               OPP(NOFIL+1,I) = 0.0
               GO TO 887
            ENDIF
            ITOR = 1 + IFIX((DISEC - XMIN)/DX)
            IF (ITOR.EQ.NOPO) THEN
               ITOR = ITOR - 1
            ENDIF
            AA = (SECTOR(ITOR+1) - SECTOR(ITOR))/DX
            BB = SECTOR(ITOR) - AA*(XMIN + FLOAT(ITOR-1)*DX)
            SECCOR = AA*DISEC + BB
            OPP(NOFIL,I) = ONS(1,I)*SS**4/SECCOR
            OPP(NOFIL+1,I) = ONS(2,I)*SS**4/SECCOR
C           PLANAR PLATES:
            OPP(NOFIL,I) = OPP(NOFIL,I)/(COS(TETA)**3)
            OPP(NOFIL+1,I) = OPP(NOFIL+1,I)/(COS(TETA)**3)
  887       CONTINUE
         ENDDO
      ELSE
         DO I = 1,NOS
            OPP(NOFIL,I) = ONS(1,I)
            OPP(NOFIL+1,I) = ONS(2,I)
         ENDDO
      ENDIF

      IPLA =1
      DO I = 1,NOS
      opp_ave(i)=((OPP(1,I)+OPP(2,I))/(100*2))
      enddo
      
      factor = 0.0000
      
c**********************************
      outfile = 'output'//CHAR(96+k)//'.curv'
c      outfile = 'output'//k//'.curv'


      OPEN(UNIT=21,FILE=outfile,FORM='FORMATTED',STATUS='UNKNOWN')
      WRITE(21,'(A)') '1  5'

c      nmin = DINT(smin/deltas + 0.0001)
      nmin = AINT(smin/deltas + 0.0001)
      nmax = AINT(smax/deltas + 0.0001)     
c      nmax = DINT(smax/deltas + 0.0001)
      WRITE(21,'(I3)') k
      WRITE(21,'(3F10.5,2I4)') wavle,cadist,deltas,nmin,nmax
      DO j=1,nmax-nmin+1
      WRITE(21,'(F12.5)') opp_ave(j)
      END DO
      CLOSE(21)

      WRITE(*,'(/1X,A,A11,A)')'Result on ',outfile,'.'

678   continue

999   CONTINUE
      close(77)    

      END
