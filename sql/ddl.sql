DROP DATABASE IF EXISTS idb;

CREATE DATABASE idb;
USE idb;

CREATE TABLE account (
    account_id varchar(30) PRIMARY KEY,
    passwd varchar(255) NOT NULL
);

CREATE TABLE machine (
    machine_id int PRIMARY KEY AUTO_INCREMENT,
    machine_name varchar(20)
);

CREATE TABLE device (
    device_id varchar(255) PRIMARY KEY,
    device_name varchar(20)
);

CREATE TABLE report (
    report_id int PRIMARY KEY AUTO_INCREMENT,
    report_name varchar(20),
    updated datetime NOT NULL
);

CREATE TABLE data (
    device_id varchar(255) NOT NULL,
    category varchar(20) NOT NULL,
    created datetime(6) NOT NULL,
    value real NOT NULL,
    FOREIGN KEY (device_id) REFERENCES device(device_id) ON DELETE CASCADE
);

CREATE TABLE owns (
    account_id varchar(20) NOT NULL,
    device_id varchar(255) NOT NULL,
    FOREIGN KEY (account_id) REFERENCES account(account_id) ON DELETE CASCADE,
    FOREIGN KEY (device_id) REFERENCES device(device_id) ON DELETE CASCADE
);

CREATE TABLE manages (
    account_id varchar(20) NOT NULL,
    machine_id int NOT NULL,
    FOREIGN KEY (account_id) REFERENCES account(account_id) ON DELETE CASCADE,
    FOREIGN KEY (machine_id) REFERENCES machine(machine_id) ON DELETE CASCADE
);

CREATE TABLE consists (
    machine_id int NOT NULL,
    device_id varchar(255) NOT NULL,
    FOREIGN KEY (machine_id) REFERENCES machine(machine_id) ON DELETE CASCADE,
    FOREIGN KEY (device_id) REFERENCES device(device_id) ON DELETE CASCADE
);

CREATE TABLE reserves (
    account_id varchar(20) NOT NULL,
    report_id int NOT NULL,
    FOREIGN KEY (account_id) REFERENCES account(account_id) ON DELETE CASCADE,
    FOREIGN KEY (report_id) REFERENCES report(report_id) ON DELETE CASCADE
);

CREATE TABLE refers (
    report_id int NOT NULL,
    machine_id int NOT NULL,
    FOREIGN KEY (report_id) REFERENCES report(report_id) ON DELETE CASCADE,
    FOREIGN KEY (machine_id) REFERENCES machine(machine_id) ON DELETE CASCADE
);

CREATE TABLE plans (
    report_id int NOT NULL,
    period int NOT NULL, # 0: month, 1: week
    day int NOT NULL, # 0~30: date(0 for 1st, 1 for 2nd, ...), 0~6: day(0 for Sunday, 1 for Monday, ...)
    FOREIGN KEY (report_id) REFERENCES report(report_id) ON DELETE CASCADE
);
