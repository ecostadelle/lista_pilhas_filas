
``` graphviz
digraph structs {
    rankdir = LR;
    node [shape=record];
    rank = 0 ;
    p00 [label="<f0>p|<f1>E|<f2>D|<f3>C|<f4>B|<f5>A"];
    p10 [label="<f0>p|<f1>D|<f2>C|<f3>B|<f4>A|<f5>E"];
    p20 [label="<f0>p|<f1>C|<f2>B|<f3>A|<f4>D|<f5>E"];
    p30 [label="<f0>p|<f1>B|<f2>A|<f3>C|<f4>D|<f5>E"];
    p40 [label="<f0>p|<f1>A|<f2>B|<f3>C|<f4>D|<f5>E"];
    eA0 [label="<f0>auxiliar|<f1>E"];
    eA1 [label="<f0>auxiliar|<f1>D"];
    eA2 [label="<f0>auxiliar|<f1>C"];
    eA3 [label="<f0>auxiliar|<f1>B"];
    p01 [label="<f0>p1|<f1>D|<f2>C|<f3>B|<f4>A"];
    p11 [label="<f0>p1|<f1>C|<f2>B|<f3>A"];
    p21 [label="<f0>p1|<f1>B|<f2>A"];
    p31 [label="<f0>p1|<f1>A"];
    p00:f1 -> eA0:f1 -> p10:f5;
    p00:f2 -> p01:f1 -> p10:f1 -> eA1:f1 -> p20:f4;
    p00:f3 -> p01:f2 -> p10:f2 -> p11:f1 -> p20:f1 -> eA2:f1 -> p30:f3;
    p00:f5 -> p01:f4 -> p10:f4 -> p11:f3 -> p20:f3 -> p21:f2 -> p30:f2 -> p31:f1 -> p40:f1;
    p00:f4 -> p01:f3 -> p10:f3 -> p11:f2 -> p20:f2 -> p21:f1 -> p30:f1 -> eA3:f1 -> p40:f2;
}
```