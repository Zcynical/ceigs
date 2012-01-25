

#include "ceigs.h"
#include "ceigs_cs.h"

#include <suitesparse/cs.h>

#include <math.h>
#include <assert.h>
#include <string.h>


/* DSDRV2 */
static void* eigs_dsdrv2_init_lu( int n, const void *data_A, const void *data_M,
      const EigsOpts_t *opts );
/* DSDRV3 */
static void* eigs_dsdrv3_init_lu( int n, const void *data_A, const void *data_M,
      const EigsOpts_t *opts );
/* DSDRV4 */
static void* eigs_dsdrv4_init_lu( int n, const void *data_A, const void *data_M,
      const EigsOpts_t *opts );


const EigsDriverGroup_t eigs_drv_lu = {
   .driver1 = {
      .init  = NULL,
      .free  = NULL,
      .dsdrv = eigs_dsdrv1_cs,
   },
   .driver2 = {
      .init  = eigs_dsdrv2_init_lu,
      .free  = eigs_dsdrv2_free_cs,
      .dsdrv = eigs_dsdrv2_cs,
   },
   .driver3 = {
      .init  = eigs_dsdrv3_init_lu,
      .free  = eigs_dsdrv3_free_cs,
      .dsdrv = eigs_dsdrv3_cs,
   },
   .driver4 = {
      .init  = eigs_dsdrv4_init_lu,
      .free  = eigs_dsdrv4_free_cs,
      .dsdrv = eigs_dsdrv4_cs,
   },
   .driver5 = {
      .init  = NULL,
      .free  = NULL,
      .dsdrv = NULL,
   },
   .driver6 = {
      .init  = NULL,
      .free  = NULL,
      .dsdrv = NULL,
   },
};


/* DSDRV1 */
static void* eigs_dsdrv2_init_lu( int n, const void *data_A, const void *data_M,
      const EigsOpts_t *opts )
{
   return eigs_dsdrv2_init_cs( n, data_A, data_M, opts, CS_FACT_LU );
}
/* DSDRV3 */
static void* eigs_dsdrv3_init_lu( int n, const void *data_A, const void *data_M,
      const EigsOpts_t *opts )
{
   return eigs_dsdrv3_init_cs( n, data_A, data_M, opts, CS_FACT_LU );
}
/* DSDRV4 */
static void* eigs_dsdrv4_init_lu( int n, const void *data_A, const void *data_M,
      const EigsOpts_t *opts )
{
   return eigs_dsdrv4_init_cs( n, data_A, data_M, opts, CS_FACT_LU );
}


