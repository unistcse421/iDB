DROP FUNCTION IF EXISTS register_device;
DROP FUNCTION IF EXISTS change_device_name;
DROP FUNCTION IF EXISTS delete_device;

delimiter $$

CREATE FUNCTION register_device(aid varchar(30), did varchar(255)) RETURNS int
    BEGIN
        INSERT INTO device VALUES(did, 'new device');
        INSERT INTO owns VALUES(aid, did);
        RETURN 1;
    END$$

CREATE FUNCTION change_device_name(did varchar(255), dname varchar(20)) RETURNS int
    BEGIN
        UPDATE device SET device_name=dname WHERE device_id=did;
        RETURN 1;
    END$$

CREATE FUNCTION delete_device(did varchar(255)) RETURNS int
    BEGIN
        DELETE FROM data WHERE device_id=did;
        DELETE FROM consists WHERE device_id=did;
        DELETE FROM owns WHERE device_id=did;
        DELETE FROM device WHERE device_id=did;
        RETURN 1;
    END$$

delimiter ;
