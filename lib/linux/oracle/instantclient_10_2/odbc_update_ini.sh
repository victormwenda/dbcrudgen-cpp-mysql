#!/bin/sh
#
# $Header: odbc/utl/odbc_update_ini.sh /st_rdbms_10.2/6 2009/05/08 06:53:20 ksowmya Exp $
#
# odbc_update_ini.sh
#
# Copyright (c) 2005, 2009, Oracle and/or its affiliates. All rights reserved. 
#
#    NAME
#      odbc_update_ini.sh 
#       - updates <DM-HOME>/etc/odbcinst.ini and ~/.odbc.ini
#
#    DESCRIPTION
#      Usage: odbc_update_ini.sh <ODBCDM_HOME> 
#                            [<Install-location>] [Driver-name>] [<DSN>]
#      The script should be run from the directory where ODBC driver .so is
#      available if installation location is not passed as arg-2.
#
#    NOTES
#      <other useful comments, qualifications, etc.>
#
#    MODIFIED   (MM/DD/YY)
#    ksowmya     05/07/09 - Backport ksowmya_bug-7704827 from main
#    akapila     09/26/05 - modified for bug4608183. 
#    akapila     05/04/06 - Backport akapila_bug-4608183 from main__nt 
#    akapila     09/26/05 - modified for bug4608183. 
#    akapila     05/04/06 - Backport akapila_bug-4608183 from main__nt 
#    subanerj    09/26/05 - Fixed bug 4612520. Added optional arguments.
#    subanerj    05/02/06 - Backport subanerj_bug-4612520 from st_rdbms_10.2xe 
#    akapila     03/06/06 - modified for bug-4150034. 
#    akapila     03/06/06 - modified for bug-4150034. 
#    akapila     11/29/05 - created for bug 4741148. 
#    akapila     11/29/05 - Creation
#
# =========================================================================

# ODBCDM_HOME needs to be passed as arg-1
if [ ! "$1" ]
then
   echo " *** Please pass ODBCDM_HOME as arg-1, and optional arguments -"
   echo " *** Install location (arg-2), Driver name (arg-3) & DSN (arg-4)."
   echo " *** Usage:  odbc_update_ini.sh <ODBCDM_Home> [<Install_Location>] [<Driver_Name>] [<DSN>]"
   exit
else
   ODBCDM_HOME="$1"
fi

# Check whether Driver Manager is installed or not
if [ ! -f  $ODBCDM_HOME/etc/odbc.ini  -o  ! -f $ODBCDM_HOME/etc/odbcinst.ini ]
then
   echo " *** INI file not found. Driver Manager not installed!"
   exit
fi

# Add driver entry in $ODBCDM_HOME/etc/odbcinst.ini file
#
DRIVER_DESCRIPTION="Oracle ODBC driver for Oracle 10g"

# If a driver location is passed, use that or use the current directory
if [ ! "$2" ]
     then
        DRIVER_LOCATION=`pwd`
     else
        DRIVER_LOCATION="$2"
fi

# Check for Driver name
if [ ! "$3" ]
     then
        DRIVER_NAME="Oracle 10g ODBC driver"
     else
        DRIVER_NAME="$3"
fi

# We know driver .so name 
SO_NAME=libsqora.so.10.1

echo "
[$DRIVER_NAME]
Description     = $DRIVER_DESCRIPTION
Driver          = $DRIVER_LOCATION/$SO_NAME
Setup           =
FileUsage       =
CPTimeout       =
CPReuse         = " >> $ODBCDM_HOME/etc/odbcinst.ini
			      
# Add DSN entry 
# If a DSN name is passed, use that or use the default name
if [ ! "$4" ]
     then
        DSN="OracleODBC-10g"
     else
        DSN="$4"
fi
			      
echo "
[$DSN]
Application Attributes = T
Attributes = W
BatchAutocommitMode = IfAllSuccessful
BindAsFLOAT = F
CloseCursor = F
DisableDPM = F
DisableMTS = T
Driver = $DRIVER_NAME
DSN = $DSN
EXECSchemaOpt =
EXECSyntax = T
Failover = T
FailoverDelay = 10
FailoverRetryCount = 10
FetchBufferSize = 64000
ForceWCHAR = F
Lobs = T
Longs = T
MetadataIdDefault = F
QueryTimeout = T
ResultSets = T
ServerName = 
SQLGetData extensions = F
Translation DLL =
Translation Option = 0
DisableRULEHint = T
UserID = 
UseOCIDescribeAny=F
"  >> $HOME/.odbc.ini

# Add DSN entry in "ODBC Data Sources" list
#
cat $HOME/.odbc.ini | sed "s/\[ODBC Data Sources\]/\[ODBC Data Sources\]\n$DSN = $DRIVER_DESCRIPTION/g" > odbc.ini
mv odbc.ini $HOME/.odbc.ini

