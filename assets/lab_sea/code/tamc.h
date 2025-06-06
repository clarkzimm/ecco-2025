c     ================================================================
c     HEADER TAMC
c     ================================================================
c
c     o Header for the use of the Tangent Linear and Adjoint Model
c       Compiler (TAMC).
c
c     started: Christian Eckert eckert@mit.edu  04-Feb-1999
c
c     changed: Patrick Heimbach heimbach@mit.edu 06-Jun-2000
c              - New parameter nlevchk_0 for dimensionalising common
c                blocks in the undef ALLOW_TAMC_CHECKPOINTING case
c              - nhreads_chkpt was declared at the wrong place
c
c
c     ================================================================
c     HEADER TAMC
c     ================================================================

c     TAMC checkpointing parameters:
c     ==============================
c
c     The checkpointing parameters have to be consistent with other model
c     parameters and variables. This has to be checked before the model is
c     run.
c
c     nyears_chkpt   - Number of calendar years affected by the assimilation
c                      experiment; nyears_chkpt has to be at least equal to
c                      the result of cal_IntYears(mythid).
c     nmonths_chkpt  - Number of months per year; nmonth_chkpt has to
c                      be at least equal to nmonthyear.
c     ndays_chkpt    - Number of days per month; nday_chkpt has to be
c                      at least equal to nmaxdaymonth.
c     nsteps_chkpt   - Number of steps per day; nsteps_chkpt has to
c                      be at least equal to cal_nStepDay(mythid)
c     ncheck_chkpt   - Number of innermost checkpoints.
c
c     ngeom_chkpt    - Geometry factor.
c     nthreads_chkpt - Number of threads to be used; nth_chkpt .eq. nTx*nTy

      integer nyears_chkpt
      integer nmonths_chkpt
      integer ndays_chkpt
      integer ngeom_chkpt
      integer ncheck_chkpt
      integer nthreads_chkpt

      parameter (nyears_chkpt   =          1 )
      parameter (nmonths_chkpt  =         12 )
      parameter (ndays_chkpt    =         31 )
      parameter (ngeom_chkpt    = nr*nsx*nsy )
      parameter (ncheck_chkpt   =          6 )
      parameter ( nthreads_chkpt = 1 )

#ifdef ALLOW_TAMC_CHECKPOINTING

      integer    nchklev_1
c      parameter( nchklev_1      =   2 )
      integer    nchklev_2
c      parameter( nchklev_2      =   2 )
      integer    nchklev_3
c      parameter( nchklev_3      =   4 )
cph      integer    nchklev_4
cph      parameter( nchklev_4      =   4 )
c      parameter( nchklev_1      =  4 )
c      parameter( nchklev_2      =  144 )
      parameter( nchklev_1      =  96 )
      parameter( nchklev_2      =  6 )
      parameter( nchklev_3      =  1 )

c--   Note always check for the correct sizes of the common blocks!

#else /* ALLOW_TAMC_CHECKPOINTING undefined */

      integer    nchklev_0
      parameter( nchklev_0      =   48 )

#endif /* ALLOW_TAMC_CHECKPOINTING */

c     TAMC keys:
c     ==========
c
c     The keys are used for storing and reading data of the reference
c     trajectory.
c
c     The convention used here is:
c                                    ikey_<name>
c
c     which means that this key is used in routine <name> for reading
c     and writing data.

      common /tamc_keys_i/
     &                     ikey_dynamics,
     &                     ikey_yearly,
     &                     ikey_daily_1,
     &                     ikey_daily_2,
     &                     iloop_daily

      integer ikey_dynamics
      integer ikey_yearly
      integer ikey_daily_1
      integer ikey_daily_2
      integer iloop_daily

      INTEGER    isbyte
C     For smaller tapes replace 8 by 4.
      PARAMETER( isbyte    = 8 )

      INTEGER    maximpl
      PARAMETER( maximpl   = 6 )
#ifdef ALLOW_PTRACERS
cph moved this to PTRACERS_SIZE.h
cph      INTEGER    maxpass
cph      PARAMETER( maxpass     = PTRACERS_num + 2 )
#else
      INTEGER    maxpass
      PARAMETER( maxpass   = 2 )
#endif
      INTEGER    maxcube
      PARAMETER( maxcube   = 2 )

c     ================================================================
c     END OF HEADER TAMC
c     ================================================================
