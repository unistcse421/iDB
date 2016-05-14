DELETE FROM owns WHERE machine_id=@machine_id;
DELETE FROM refers WHERE machine_id=@machine_id;
DELETE FROM machine WHERE machine_id=@machine_id;
