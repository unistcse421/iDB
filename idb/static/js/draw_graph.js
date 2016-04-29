var x = [10, 20, 30, 40, 50, 60, 70, 80, 90, 100];
var w = 200, h = 100;

var svg = d3.select("article")
            .append("svg")
            .attr("width", w).attr("height", h);

svg.selectAll("rect")
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
