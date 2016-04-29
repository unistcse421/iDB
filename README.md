### CSE421 Term Project
# iDB - Smart Factory System

This project is done in UNIST CSE421 Database System Class.

Our project topic is making a monitoring system for smart factory.
- Data acquisition from machine using microcontroller.
- Store the data in database management system.
- User can monitor the data via web based dashboard monitoring system
- User can control the data they want to see and find useful information from data visualization.
- Send the report regularly to the user via e-mail.

#### System Installation Tutorial
- Download Git
- Open terminal and go to server root
- Add the file index.php and add the code:
```php
<?php header("Location: iDB"); ?>
```
- ```git clone https://github.com/unistcse421/iDB.git```
- ```cd iDB/idb/static/js```
- ```git clone https://github.com/mbostock/d3.git```

#### Log
- 2016.03.29. - Proposal added
- 2016.04.25. - Web server construction implemented
- 2016.04.29. - d3.js library included
