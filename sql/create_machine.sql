INSERT INTO machine (machine_name) VALUES('machine');
INSERT INTO owns VALUES(@id, LAST_INSERT_ID());
