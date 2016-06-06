

var drawGraph1 = function(data) {

//   console.log(data['a1']);
  var tData = data['a1'];

  d3.select("#ProbChart").selectAll("svg").remove();

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

  var svg1 = d3.select("#ProbChart").append("svg")
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
//       .selectAll("text").remove();

  svg1.append("path")
      .datum(tData)
      .attr("class", "line")
      .attr("d", line)
      .on("mouseover", function(d,i) { svg1.append("g").attr("class","date").attr("x", x(i)).attr("y", height-d["value"]-5).text(d["date"]); })
      .on("mouseout", function(d,i) { svg1.selectAll(".date").remove(); });
}


var drawGraph2 = function(data) {

  var tData = data['a2'];

  d3.select("#FSChart").selectAll("svg").remove();

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

  var svg1 = d3.select("#FSChart").append("svg")
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
      .call(xAxis)
      .selectAll("text").remove();

  svg1.append("path")
      .datum(tData)
      .attr("class", "line")
      .attr("d", line)
      .on("mouseover", function(d,i) { svg1.append("g").attr("class","date").attr("x", x(i)).attr("y", height-d["value"]-5).text(d["date"]); })
      .on("mouseout", function(d,i) { svg1.selectAll(".date").remove(); });
}

var drawGraph3 = function(data) {

  var tData = data['a1'];
  var hData = data['a2'];

  var aData = [];

  for (var i = 0; i < tData.length; i++) {
    aData.push((Number(tData[i].value) + Number(hData[i].value))/2);
  }

//   console.log(aData);

  d3.select("#lineChart").selectAll("svg").remove();

  var margin = {top: 20, right: 20, bottom: 30, left: 40},
      width = 960 - margin.left - margin.right,
      height = 300 - margin.top - margin.bottom;

  var x = d3.scale.linear()
      .domain([0, 100])
      .range([0, width]);

  var y = d3.scale.linear()
      .domain([15, 45])
      .range([height, 0]);

  var xAxis = d3.svg.axis()
      .scale(x)
      .orient("bottom");

  var yAxis = d3.svg.axis()
      .scale(y)
      .orient("left");

  var svg = d3.select("#lineChart").append("svg")
      .attr("width", width + margin.left + margin.right)
      .attr("height", height + margin.top + margin.bottom)
    .append("g")
      .attr("transform", "translate(" + margin.left + "," + margin.top + ")");


//     x.domain(data.map(function(d) { return d.letter; }));
//     y.domain([0, d3.max(data, function(d) { return d.frequency; })]);

    svg.append("g")
        .attr("class", "x axis")
        .attr("transform", "translate(0," + height + ")")
        .call(xAxis);

     svg.append("g")
        .attr("class", "y axis")
        .call(yAxis);
        /*
      .append("text")
        .attr("transform", "rotate(-90)")
        .attr("y", 6)
        .attr("dy", ".71em")
        .style("text-anchor", "end")
        .text("Frequency"); */

    svg.selectAll(".bar")
        .data(aData)
      .enter().append("rect")
        .attr("class", "bar")
        .attr("x", function(d,i) { return x(i) + 0.1; })
        .attr("width", 7)
        .attr("y", function(d) { return y(d); })
        .attr("height", function(d) { return height - y(d); })
        .on("mouseover", function(d,i) { mouseX = d3.mouse(this)[0]; mouseY = d3.mouse(this)[1]; svg.append("text").attr("x", mouseX).attr("y",mouseY).text(tData[i]["created"]); });
//         .on("mouseout", function(d,i) { svg.selectAll(".date").remove(); });

}


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
  drawGraph3(dbData);
}
