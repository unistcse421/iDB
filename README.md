### CSE421 Term Project
# iDB - Smart Factory System

This project is done in UNIST CSE421 Database Systems Class.

Our project topic is making a monitoring system for smart factory.
- Data acquisition from machine using microcontroller.
- Store the data in database management system.
- User can monitor the data via web based dashboard monitoring system
- User can control the data they want to see and find useful information from data visualization.
- Send the report regularly to the user via e-mail.

#### Imported Libraries & Frameworks
- [d3.js](https://d3js.org)

#### System Installation Tutorial
- Download Git
- Open terminal and go to server root
- Add the file index.php and add the code:
```php
<?php header("Location: iDB"); ?>
```
If you want to locate the directory in another location, please modify ```ROOT``` and ```HTML_ROOT``` in ```iDB/idb/config/path.php```.
- ```git clone https://github.com/unistcse421/iDB.git```
- ```cd iDB/idb/static/js```
- ```rmdir d3```
- ```git clone https://github.com/mbostock/d3.git```

We recommend you to download MariaDB rather than MySQL, or download MySQL over 5.6 version, since MySQL under 5.5 version doesn't support millisecond and microsecond in time record.
