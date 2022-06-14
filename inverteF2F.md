``` graphviz
digraph inverteF2F {
    compound=true;
    rankdir = LR;
    node [shape=record];
    f00 [label="<f0>f|<f1>E|<f2>D|<f3>C|<f4>B|<f5>A"];
    f10 [label="<f0>f|<f1>D|<f2>C|<f3>B|<f4>A"];
    f20 [label="<f0>f|<f1>C|<f2>B|<f3>A"];
    f30 [label="<f0>f|<f1>B|<f2>A"];
    f50 [label="<f0>f|<f1>A|<f2>B|<f3>C|<f4>D|<f5>E"];
    f01 [label="<f0>f1|<f1>E"];
    f11 [label="<f0>f1|<f1>D|<f2>E"];
    f21 [label="<f0>f1|<f1>C|<f2>D|<f3>E"];
    f31 [label="<f0>f1|<f1>B|<f2>C|<f3>D|<f4>E"];
    f41 [label="<f0>f1|<f1>A|<f2>B|<f3>C|<f4>D|<f5>E"];
    f02 [label="<f0>f2|<f1>D|<f2>C|<f3>B|<f4>A"];
    f12 [label="<f0>f2|<f1>C|<f2>B|<f3>A"];
    f22 [label="<f0>f2|<f1>B|<f2>A"];
    f32 [label="<f0>f2|<f1>A"];
    
    {rank = same f02 f01}

    f00:f1 -> f01:f1 [color=darkslategray];
    f00:f2 -> f02:f1 -> f10:f1 -> f11:f1 [color=tomato];
    f00:f3 -> f02:f2 -> f10:f2 -> f12:f1 -> f20:f1 -> f21:f1 [color=darkgreen];
    f00:f4 -> f02:f3 -> f10:f3 -> f12:f2 -> f20:f2 -> f22:f1 -> f30:f1 -> f31:f1 [color=darkslateblue];
    f00:f5 -> f02:f4 -> f10:f4 -> f12:f3 -> f20:f3 -> f22:f2 -> f30:f2 -> f32:f1 -> f41:f1 [color=darkorange];
    f41:f1 -> f50:f1 [color=darkorange];
    f41:f2 -> f50:f2 [color=darkslateblue];
    f41:f3 -> f50:f3 [color=darkgreen];
    f41:f4 -> f50:f4 [color=tomato];
    f41:f5 -> f50:f5 [color=darkslategray]; 
    f01:f0 -> f11:f0 -> f21:f0 -> f31:f0 -> f41:f0 [style="invis"];
    f32:f1 -> f41:f5  [style="invis"];
}
```