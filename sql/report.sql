DROP FUNCTION IF EXISTS create_report;
DROP FUNCTION IF EXISTS change_report_name;
DROP FUNCTION IF EXISTS delete_report;

delimiter $$

CREATE FUNCTION create_report(aid varchar(30)) RETURNS int
    BEGIN
        INSERT INTO report (report_name) VALUES('new report');
        INSERT INTO reserves VALUES(aid, LAST_INSERT_ID());
        RETURN 1;
    END$$

CREATE FUNCTION change_report_name(rid int, rname varchar(20)) RETURNS int
    BEGIN
        UPDATE report SET report_name=rname WHERE report_id=rid;
        RETURN 1;
    END$$

CREATE FUNCTION delete_report(rid int) RETURNS int
    BEGIN
        DELETE FROM reserves WHERE report_id=rid;
        DELETE FROM refers WHERE report_id=rid;
        DELETE FROM report WHERE report_id=rid;
        RETURN 1;
    END$$

delimiter ;
