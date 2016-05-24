DROP FUNCTION IF EXISTS create_machine;
DROP FUNCTION IF EXISTS change_machine_name;
DROP FUNCTION IF EXISTS delete_machine;
DROP FUNCTION IF EXISTS attach_device;
DROP FUNCTION IF EXISTS detach_device;

delimiter $$

CREATE FUNCTION create_machine(aid varchar(30)) RETURNS int
    BEGIN
        INSERT INTO machine (machine_name) VALUES('new machine');
        INSERT INTO manages VALUES(aid, LAST_INSERT_ID());
        RETURN 1;
    END$$

CREATE FUNCTION change_machine_name(mid int, mname varchar(20)) RETURNS int
    BEGIN
        UPDATE machine SET machine_name=mname WHERE machine_id=mid;
        RETURN 1;
    END$$

CREATE FUNCTION delete_machine(mid int) RETURNS int
    BEGIN
        DELETE FROM manages WHERE machine_id=mid;
        DELETE FROM refers WHERE machine_id=mid;
        DELETE FROM consists WHERE machine_id=mid;
        DELETE FROM machine WHERE machine_id=mid;
        RETURN 1;
    END$$

CREATE FUNCTION attach_device(mid int, did varchar(255)) RETURNS int
    BEGIN
        INSERT INTO consists VALUES(mid, did);
        RETURN 1;
    END$$

CREATE FUNCTION detach_device(mid int, did varchar(255)) RETURNS int
    BEGIN
        DELETE FROM consists WHERE machine_id=mid AND device_id=did;
        RETURN 1;
    END$$

delimiter ;
