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
        DELETE FROM account WHERE account_id=aid;
        RETURN 1;
    END$$

delimiter ;
