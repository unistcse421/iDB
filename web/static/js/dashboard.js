

var drawGraph1 = function(data) {

  d3.select("#lineChart").selectAll("svg").remove();

  var superscript = "⁰¹²³⁴⁵⁶⁷⁸⁹",
      formatPower = function(d) { return (d + "").split("").map(function(c) { return superscript[c]; }).join(""); };

  var margin = {top: 40.5, right: 40.5, bottom: 50.5, left: 60.5},
      width = 960 - margin.left - margin.right,
      height = 500 - margin.top - margin.bottom;

  var x = d3.scale.linear()
      .domain([0, 100])
      .range([0, width]);

  var y = d3.scale.log()
      .base(Math.E)
      .domain([Math.exp(0), Math.exp(9)])
      .range([height, 0]);

  var xAxis = d3.svg.axis()
      .scale(x)
      .orient("bottom");

  var yAxis = d3.svg.axis()
      .scale(y)
      .orient("left")
      .tickFormat(function(d) { return "e" + formatPower(Math.round(Math.log(d))); });

  var line = d3.svg.line()
      .x(function(d) { return x(d[0]); })
      .y(function(d) { return y(d[1]); });

  var svg1 = d3.select("#lineChart").append("svg")
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
      .datum(d3.range(100).map(function(x) { return [x, x * x + x + 1]; }))
      .attr("class", "line")
      .attr("d", line);
}

/*
var drawGraph2 = function(data) {

  var x = [10, 20, 30, 40, 50, 60, 70, 80, 90, 100];

  var w = 410, h = 240;
  var m = {top:30, bottom: 30, left: 30, right: 30};
  var svg2 = d3.select("#probChart")
              .append("svg")
              .attr("width", w + m.left + m.right).attr("height", h + m.top + m.bottom)
              .append("g")
              .attr("transform", "translate(" + m.left + "," + m.top + ")");;

   var x2 = d3.scale.linear()
      .domain([0 100])
      .range([0, h]);

  svg2.selectAll("rect")
      .data(x)
      .enter()
      .append("rect")
      .attr("x", function(d, i) {
          return i*(w/x.length);
      })
      .attr("y", function(d) {
          return h - d;
      })
      .attr("width", w/x.length - 1)
      .attr("height", function(d) {
          return d;
      })
      .attr("fill", function(d) {
          return "hotpink";
      });
}
 */

/* var margin = {top: 20, right: 80, bottom: 30, left: 50},
    width = 960 - margin.left - margin.right,
    height = 500 - margin.top - margin.bottom;

var parseDate = d3.time.format("%Y%m%d").parse;

var x = d3.time.scale().range([0, width]);

var y = d3.scale.linear().range([height, 0]);

var color = d3.scale.category10();

var xAxis = d3.svg.axis()
    .scale(x)
    .orient("bottom");

var yAxis = d3.svg.axis()
    .scale(y)
    .orient("left");

var line = d3.svg.line()
    .interpolate("basis")
    .x(function(d) { return x(d.date); })
    .y(function(d) { return y(d.temperature); });

var svg = d3.select("#lineChart").append("svg")
    .attr("width", width + margin.left + margin.right)
    .attr("height", height + margin.top + margin.bottom)
  .append("g")
    .attr("transform", "translate(" + margin.left + "," + margin.top + ")");

d3.tsv(ROOT + "/static/js/data.tsv", function(error, data) {
  if (error) throw error;

  color.domain(d3.keys(data[0]).filter(function(key) { return key !== "date"; }));

  data.forEach(function(d) {
    d.date = parseDate(d.date);
  });

  var cities = color.domain().map(function(name) {
    return {
      name: name,
      values: data.map(function(d) {
        return {date: d.date, temperature: +d[name]};
      })
    };
  });

  x = d3.time.scale().range([0, width]).domain(d3.extent(data, function(d) { return d.date; }));

  y = d3.scale.linear().range([height, 0]).domain([
    d3.min(cities, function(c) { return d3.min(c.values, function(v) { return v.temperature; }); }),
    d3.max(cities, function(c) { return d3.max(c.values, function(v) { return v.temperature; }); })
  ]);

  svg.append("g")
      .attr("class", "x axis")
      .attr("transform", "translate(0," + height + ")")
      .call(xAxis);

  svg.append("g")
      .attr("class", "y axis")
      .call(yAxis)
    .append("text")
      .attr("transform", "rotate(-90)")
      .attr("y", 6)
      .attr("dy", ".71em")
      .style("text-anchor", "end")
      .text("Temperature (ºF)");

  var city = svg.selectAll(".city")
      .data(cities)
    .enter().append("g")
      .attr("class", "city");

  city.append("path")
      .attr("class", "line")
      .attr("d", function(d) { return line(d.values); })
      .style("stroke", function(d) { return color(d.name); });

  city.append("text")
      .datum(function(d) { return {name: d.name, value: d.values[d.values.length - 1]}; })
      .attr("transform", function(d) { return "translate(" + x(d.value.date) + "," + y(d.value.temperature) + ")"; })
      .attr("x", 3)
      .attr("dy", ".35em")
      .text(function(d) { return d.name; });
});
 */

// drawGraph1();
// drawGraph2();


//-------------------------------------------------------------


/* var width2 = 470,
    height2 = 300;

var data2 = d3.range(20).map(function() { return [Math.random() * width, Math.random() * height]; });

var color = d3.scale.category10();

d3.select("#FSChart")
  .append("svg")
    .attr("width", width2)
    .attr("height", height2)
  .selectAll("circle")
    .data(data2)
  .enter().append("circle")
    .attr("transform", function(d) { return "translate(" + d + ")"; })
    .attr("r", 10)
    .style("fill", function(d, i) { return color(i); });
 */



//-----------------------------------------------------------

setInterval(getData, 2000);
var dbData;

function getData() {
    $(document).ready(function() {
        jQuery.ajax({
            type:"GET",
            url:ROOT + "/process/echo_data.php?machine_id=" + parseInt(document.getElementById('json').innerHTML),
            success : function(data) {
//                 document.getElementById('result').innerHTML = data;
                dbData = data;
            },
            error : function(xhr, status, error) {
//                 document.getElementById('result').innerHTML = error;
            }
        });
    });

    drawGraph1(dbData);
}
