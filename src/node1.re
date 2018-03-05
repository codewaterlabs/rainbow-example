let vertexSource = {|
    precision mediump float;
    attribute vec2 position;
    varying vec2 posColor;
    void main() {
        posColor = (position + 1.0) * 0.5;
        gl_Position = vec4(position, 0.0, 1.0);
    }
|};

let fragmentSource = {|
    precision mediump float;
    varying vec2 posColor;

    void main() {
        gl_FragColor = vec4(posColor, 0.0, 1.0);
    }
|};

let makeNode = () =>
  Scene.(
    Scene.makeNode(
      ~vertShader=Gpu.Shader.make(vertexSource),
      ~fragShader=Gpu.Shader.make(fragmentSource),
      ~size=Dimensions(Scale(1.0), Scale(1.0)),
      ()
    )
  );
