DROP FUNCTION IF EXISTS create_account;
DROP FUNCTION IF EXISTS delete_account;

delimiter $$

CREATE FUNCTION create_account(aid varchar(30), pw varchar(20)) RETURNS int
    BEGIN
        INSERT INTO account VALUES(aid, PASSWORD(pw));
        RETURN 1;
    END$$

CREATE FUNCTION delete_account(aid varchar(30)) RETURNS int
    BEGIN
        DELETE FROM device WHERE device_id IN (SELECT device_id FROM owns WHERE account_id=aid);
        DELETE FROM machine WHERE machine_id IN (SELECT machine_id FROM manages WHERE account_id=aid);
        DELETE FROM report WHERE report_id IN (SELECT report_id FROM reserves WHERE account_id=aid);
        DELETE FROM account WHERE account_id=aid;
        RETURN 1;
    END$$

delimiter ;
