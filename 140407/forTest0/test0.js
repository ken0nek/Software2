// test0.js //
(function() {
  var main, test;

  test = function(i, j) {
    return i * j;
  };

  main = function() {
    var i, j, k;
    i = 2;
    j = 3;
    k = test(i, j);
    if (k > 5) {
      print(">5");
    } else {
      print("<=5");
    }
  };

  main();

}).call(this);
