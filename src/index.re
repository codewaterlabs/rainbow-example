let setup = _canvas : SceneState.sceneState => {placeholder: 0};

let createRootNode = _state => Node1.makeNode();

let createScene = (canvas, state) =>
  Scene.make(canvas, state, createRootNode(state), ~drawListDebug=false, ());

let draw = (state, scene, _canvas: Gpu.Canvas.t) => {
  Scene.update(scene);
  state;
};

let keyPressed = (state, _canvas) => state;

let resize = _state => ();

let (viewportX, viewportY) = Gpu.Canvas.getViewportSize();

Scene.run(
  viewportX,
  viewportY,
  setup,
  createScene,
  draw,
  ~keyPressed,
  ~resize,
  ()
);
