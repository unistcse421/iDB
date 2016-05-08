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
    device_id int PRIMARY KEY AUTO_INCREMENT,
    device_name varchar(20)
);

CREATE TABLE report (
    report_id int PRIMARY KEY AUTO_INCREMENT,
    report_name varchar(20),
    period datetime NOT NULL,
    created datetime NOT NULL
);

CREATE TABLE data (
    device_id int NOT NULL,
    category varchar(20) NOT NULL,
    created datetime(6) NOT NULL,
    value real NOT NULL,
    FOREIGN KEY (device_id) REFERENCES device(device_id)
);

CREATE TABLE owns (
    account_id varchar(20) NOT NULL,
    machine_id int NOT NULL,
    FOREIGN KEY (account_id) REFERENCES account(account_id),
    FOREIGN KEY (machine_id) REFERENCES machine(machine_id)
);

CREATE TABLE consists (
    machine_id int NOT NULL,
    device_id int NOT NULL,
    FOREIGN KEY (machine_id) REFERENCES machine(machine_id),
    FOREIGN KEY (device_id) REFERENCES device(device_id)
);

CREATE TABLE reserves (
    account_id varchar(20) NOT NULL,
    report_id int NOT NULL,
    FOREIGN KEY (account_id) REFERENCES account(account_id),
    FOREIGN KEY (report_id) REFERENCES report(report_id)
);

CREATE TABLE refers (
    report_id int NOT NULL,
    machine_id int NOT NULL,
    FOREIGN KEY (report_id) REFERENCES report(report_id),
    FOREIGN KEY (machine_id) REFERENCES machine(machine_id)
);
