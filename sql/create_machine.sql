INSERT INTO machine (machine_name) VALUES('new machine');
INSERT INTO owns VALUES(@account_id, LAST_INSERT_ID());
