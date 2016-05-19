DROP FUNCTION IF EXISTS string_print;

delimiter $$

CREATE FUNCTION string_print( str VARCHAR(20) ) RETURNS VARCHAR(20)
    BEGIN
        DECLARE copy_str VARCHAR(20);
        SET copy_str = str;
        RETURN copy_str;
    END $$

delimiter ;

SELECT string_print('Hello world');
