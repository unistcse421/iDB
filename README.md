### CSE421 Term Project
# [iDB - Smart Factory System](http://10.16.27.158:3000)

This project is done in UNIST CSE421 Database Systems Class.

Our project topic is making a monitoring system for smart factory.
- Data acquisition from machine using microcontroller.
- Store the data in database management system.
- User can monitor the data via web based dashboard monitoring system
- User can control the data they want to see and find useful information from data visualization.
- Send the report regularly to the user via e-mail.

#### Imported Libraries & Frameworks
- [d3.js](https://d3js.org)
- [jQuery](https://jquery.com/)

#### System Installation Tutorial
- Download the server applications: Apache, PHP, MariaDB
    - We recommend you to download MariaDB rather than MySQL, or download MySQL over 5.6 version, since MySQL under 5.5 version doesn't support millisecond and microsecond in time record.
- Download Git
- Open terminal and go to server root
- Add the file index.php and add the code:
```php
<?php header("Location: iDB"); ?>
```
If you want to locate the directory in another location, please modify ```ROOT``` and ```HTML_ROOT``` in ```iDB/idb/config/path.php```.
- ```git clone https://github.com/unistcse421/iDB.git```
- ```cd sql```
- Initialize DB(Be sure that your current directory is iDB/sql)
```sql
source setup.sql;
```

#### How to use the hardware code
- Arduino
    - Register the device and remember the id
    - Modify the code as you want; the sample code only inserts the sample data into database
