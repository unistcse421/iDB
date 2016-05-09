<div class="row">
    <div class="col-6">
        <p>Monitor your factory</p>
        <img src="<?=$this->IMG?>/main.jpg" alt="Sample Img" width="100%"/>
        <h5>CSE421 Term Project</h5>
        <h2>iDB - Smart Factory System</h2>

        <p>This project is done in UNIST CSE421 Database Systems Class. <a href="https://github.com/unistcse421/iDB" target="_blank">GitHub Link</a></p>

        <p>Our project topic is making a monitoring system for smart factory.</p>
        <ul>
            <li>Data acquisition from machine using microcontroller.</li>
            <li>Store the data in database management system.</li>
            <li>User can monitor the data via web based dashboard monitoring system</li>
            <li>User can control the data they want to see and find useful information from data visualization.</li>
            <li>Send the report regularly to the user via e-mail.</li>
        </ul>
    </div>
    <div class="col-4 push-1 pull-1">
        <form action="<?=$this->PAGE?>/sign_in.php" method="post">
            <div class="field">
                <input type="email" name="id" placeholder="E-mail address" required title="E-mail address">
            </div>
            <div class="field">
                <input type="password" name="passwd" placeholder="Password" required  pattern="^[A-Za-z0-9].{8,20}$" title="8~20 characters consists of alphabet or numbers">
            </div>
            <button type="submit">Sign In</button>
            <p><a href="<?=$this->HTML_ROOT?>?page=identify">Forgot Password?</a></p>
            <p><a href="<?=$this->HTML_ROOT?>?page=sign_up">Create a New Account</a></p>
        </form>
    </div>
</div>
