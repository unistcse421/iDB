DELETE FROM owns WHERE account_id=@account_id AND machine_id=@machine_id;
DELETE FROM machine WHERE machine_id=@machine_id;
