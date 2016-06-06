

var drawGraph1 = function(data) {

//   console.log(data['a1']);
  var tData = data['a1'];

  d3.select("#Line1Chart").selectAll("svg").remove();

  var margin = {top: 40.5, right: 40.5, bottom: 50.5, left: 60.5},
      width = 470 - margin.left - margin.right,
      height = 300 - margin.top - margin.bottom;

  var x = d3.scale.linear()
      .domain([0, 100])
      .range([0, width]);

  var y = d3.scale.linear()
      .domain([10, 40])
      .range([height, 0]);

  var xAxis = d3.svg.axis()
      .scale(x)
      .orient("bottom");

  var yAxis = d3.svg.axis()
      .scale(y)
      .orient("left");
//       .tickFormat(function(d) { return "e" + formatPower(Math.round(Math.log(d))); });

  var line = d3.svg.line()
      .x(function(d,i) { return x(i); })
      .y(function(d) { return y(d["value"]); });

  var svg1 = d3.select("#Line1Chart").append("svg")
        .attr("width", width + margin.left + margin.right)
      .attr("height", height + margin.top + margin.bottom)
    .append("g")
      .attr("transform", "translate(" + margin.left + "," + margin.top + ")");

  svg1.append("g")
      .attr("class", "axis axis--y")
      .attr("transform", "translate(-10,0)")
      .call(yAxis);

  svg1.append("g")
      .attr("class", "axis axis--x")
      .attr("transform", "translate(0," + (height + 10) + ")")
      .call(xAxis);

  svg1.append("path")
      .datum(tData)
      .attr("class", "line")
      .attr("d", line);
}


var drawGraph2 = function(data) {

  var tData = data['a2'];

  d3.select("#Line2Chart").selectAll("svg").remove();

  var margin = {top: 40.5, right: 40.5, bottom: 50.5, left: 60.5},
      width = 470 - margin.left - margin.right,
      height = 300 - margin.top - margin.bottom;

  var x = d3.scale.linear()
      .domain([0, 100])
      .range([0, width]);

  var y = d3.scale.linear()
      .domain([20, 50])
      .range([height, 0]);

  var xAxis = d3.svg.axis()
      .scale(x)
      .orient("bottom");

  var yAxis = d3.svg.axis()
      .scale(y)
      .orient("left");
//       .tickFormat(function(d) { return "e" + formatPower(Math.round(Math.log(d))); });

  var line = d3.svg.line()
      .x(function(d,i) { return x(i); })
      .y(function(d) { return y(d["value"]); });

  var svg1 = d3.select("#Line2Chart").append("svg")
        .attr("width", width + margin.left + margin.right)
      .attr("height", height + margin.top + margin.bottom)
    .append("g")
      .attr("transform", "translate(" + margin.left + "," + margin.top + ")");

  svg1.append("g")
      .attr("class", "axis axis--y")
      .attr("transform", "translate(-10,0)")
      .call(yAxis);

  svg1.append("g")
      .attr("class", "axis axis--x")
      .attr("transform", "translate(0," + (height + 10) + ")")
      .call(xAxis);

  svg1.append("path")
      .datum(tData)
      .attr("class", "line")
      .attr("d", line);
}





setInterval(getData, 2000);
var dbData;

function getData() {
    $(document).ready(function() {
        jQuery.ajax({
            type:"GET",
            url:ROOT + "/process/echo_data.php?machine_id=" + parseInt(document.getElementById('json').innerHTML),
            success : function(data) {
//                 document.getElementById('result').innerHTML = data;
                dbData = jQuery.parseJSON(data);
//                console.log(dbData);
            },
            error : function(xhr, status, error) {
//                 document.getElementById('result').innerHTML = error;
            }
        });
    });

    drawGraph1(dbData);
    drawGraph2(dbData);
}
