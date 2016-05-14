DELETE FROM reserves WHERE report_id=@report_id;
DELETE FROM refers WHERE report_id=@report_id;
DELETE FROM report WHERE report_id=@report_id;
