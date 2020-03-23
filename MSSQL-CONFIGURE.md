# Configuring the MSSQL Development Environment (Microsoft ODBC 17)

The following sections explain how to install the Microsoft ODBC driver 17 from the bash shell for different Linux distributions.

[Official Reference](https://docs.microsoft.com/en-us/sql/connect/odbc/linux-mac/installing-the-microsoft-odbc-driver-for-sql-server?view=sql-server-ver15)

## Alpine Linux

#### Download the desired package(s)
 - [x] ```curl -O https://download.microsoft.com/download/e/4/e/e4e67866-dffd-428c-aac7-8d28ddafb39b/msodbcsql17_17.5.2.1-1_amd64.apk```
 - [x] ```curl -O https://download.microsoft.com/download/e/4/e/e4e67866-dffd-428c-aac7-8d28ddafb39b/mssql-tools_17.5.2.1-1_amd64.apk```


#### (Optional) Verify signature, if 'gpg' is missing install it using 'apk add gnupg':
 - [x] ```curl -O https://download.microsoft.com/download/e/4/e/e4e67866-dffd-428c-aac7-8d28ddafb39b/msodbcsql17_17.5.2.1-1_amd64.sig```
 - [x] ```curl -O https://download.microsoft.com/download/e/4/e/e4e67866-dffd-428c-aac7-8d28ddafb39b/mssql-tools_17.5.2.1-1_amd64.sig```

 - [x] ```curl https://packages.microsoft.com/keys/microsoft.asc  | gpg --import -```
 - [x] ```gpg --verify msodbcsql17_17.5.2.1-1_amd64.sig msodbcsql17_17.5.2.1-1_amd64.apk```
 - [x] ```gpg --verify mssql-tools_17.5.2.1-1_amd64.sig mssql-tools_17.5.2.1-1_amd64.apk```


#Install the package(s)
 - [x] ```sudo apk add --allow-untrusted msodbcsql17_17.5.2.1-1_amd64.apk```
 - [x] ```sudo apk add --allow-untrusted mssql-tools_17.5.2.1-1_amd64.apk```

## Debian

 - [x] ```sudo su```
 - [x] ```curl https://packages.microsoft.com/keys/microsoft.asc | apt-key add -```

### Download appropriate package for the OS version
#### Choose only ONE of the following, corresponding to your OS version

#### Debian 8
 - [x] ```curl https://packages.microsoft.com/config/debian/8/prod.list > /etc/apt/sources.list.d/mssql-release.list```

#### Debian 9
 - [x] ```curl https://packages.microsoft.com/config/debian/9/prod.list > /etc/apt/sources.list.d/mssql-release.list```

#### Debian 10
 - [x] ```curl https://packages.microsoft.com/config/debian/10/prod.list > /etc/apt/sources.list.d/mssql-release.list```

 - [x] ```exit```
 - [x] ```sudo apt-get update```
 - [x] ```sudo ACCEPT_EULA=Y apt-get install msodbcsql17```
##### optional: for bcp and sqlcmd
 - [x] ```sudo ACCEPT_EULA=Y apt-get install mssql-tools```
 - [x] ```echo 'export PATH="$PATH:/opt/mssql-tools/bin"' >> ~/.bash_profile```
 - [x] ```echo 'export PATH="$PATH:/opt/mssql-tools/bin"' >> ~/.bashrc```
 - [x] ```source ~/.bashrc```
##### optional: for unixODBC development headers
 - [x] ```sudo apt-get install unixodbc-dev```
##### optional: kerberos library for debian-slim distributions
 - [x] ```sudo apt-get install libgssapi-krb5-2```
 
## Red Hat Enterprise Server and Oracle Linux

 - [x] ```sudo su```

### Download appropriate package for the OS version
##### Choose only ONE of the following, corresponding to your OS version

#### RedHat Enterprise Server 6
 - [x] ```curl https://packages.microsoft.com/config/rhel/6/prod.repo > /etc/yum.repos.d/mssql-release.repo```

#### RedHat Enterprise Server 7
 - [x] ```curl https://packages.microsoft.com/config/rhel/7/prod.repo > /etc/yum.repos.d/mssql-release.repo```

#### RedHat Enterprise Server 8 and Oracle Linux 8
 - [x] ```curl https://packages.microsoft.com/config/rhel/8/prod.repo > /etc/yum.repos.d/mssql-release.repo```

 - [x] ```exit```
 - [x] ```sudo yum remove unixODBC-utf16 unixODBC-utf16-devel #to avoid conflicts```
 - [x] ```sudo ACCEPT_EULA=Y yum install msodbcsql17```
##### optional: for bcp and sqlcmd
 - [x] ```sudo ACCEPT_EULA=Y yum install mssql-tools```
 - [x] ```echo 'export PATH="$PATH:/opt/mssql-tools/bin"' >> ~/.bash_profile```
 - [x] ```echo 'export PATH="$PATH:/opt/mssql-tools/bin"' >> ~/.bashrc```
 - [x] ```source ~/.bashrc```
##### optional: for unixODBC development headers
 - [x] ```sudo yum install unixODBC-devel```

## SUSE Linux and Enterprise server
 - [x] ```sudo su```

#### Download appropriate package for the OS version
##### Choose only ONE of the following, corresponding to your OS version

### SUSE Linux Enterprise Server 11 SP4
##### Ensure SUSE Linux Enterprise 11 Security Module has been installed 
 - [x] ```zypper ar https://packages.microsoft.com/config/sles/11/prod.repo```

### SUSE Linux Enterprise Server 12
 - [x] ```zypper ar https://packages.microsoft.com/config/sles/12/prod.repo```

### SUSE Linux Enterprise Server 15
 - [x] ```zypper ar https://packages.microsoft.com/config/sles/15/prod.repo```
#####(Only for driver 17.3 and below)
 - [x] ```SUSEConnect -p sle-module-legacy/15/x86_64```

 - [x] ```exit```
 - [x] ```sudo ACCEPT_EULA=Y zypper install msodbcsql17```
##### optional: for bcp and sqlcmd
 - [x] ```sudo ACCEPT_EULA=Y zypper install mssql-tools```
 - [x] ```echo 'export PATH="$PATH:/opt/mssql-tools/bin"' >> ~/.bash_profile```
 - [x] ```echo 'export PATH="$PATH:/opt/mssql-tools/bin"' >> ~/.bashrc```
 - [x] ```source ~/.bashrc```
##### optional: for unixODBC development headers
 - [x] ```sudo zypper install unixODBC-devel```



## Ubuntu
 - [x] ```sudo su```
 - [x] ```curl https://packages.microsoft.com/keys/microsoft.asc | apt-key add -```

####Download appropriate package for the OS version
#### Choose only ONE of the following, corresponding to your OS version

### Ubuntu 16.04
 - [x] ```curl https://packages.microsoft.com/config/ubuntu/16.04/prod.list > /etc/apt/sources.list.d/mssql-release.list```

### Ubuntu 18.04
 - [x] ```curl https://packages.microsoft.com/config/ubuntu/18.04/prod.list > /etc/apt/sources.list.d/mssql-release.list```

### Ubuntu 19.10
 - [x] ```curl https://packages.microsoft.com/config/ubuntu/19.10/prod.list > /etc/apt/sources.list.d/mssql-release.list```

 - [x] ```exit```
 - [x] ```sudo apt-get update``` 
 - [x] ```sudo ACCEPT_EULA=Y apt-get install msodbcsql17```  
##### optional: for bcp and sqlcmd
 - [x] ```sudo ACCEPT_EULA=Y apt-get install mssql-tools```
 - [x] ```echo 'export PATH="$PATH:/opt/mssql-tools/bin"' >> ~/.bash_profile```
 - [x] ```echo 'export PATH="$PATH:/opt/mssql-tools/bin"' >> ~/.bashrc```
 - [x] ```source ~/.bashrc```
##### optional: for unixODBC development headers
```sudo apt-get install unixodbc-dev```

```$xslt
You can substitute setting the environment variable 'ACCEPT_EULA' with setting the debconf variable 'msodbcsql/ACCEPT_EULA' instead: echo msodbcsql17 msodbcsql/ACCEPT_EULA boolean true | sudo debconf-set-selections
```

