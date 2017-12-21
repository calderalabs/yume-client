module Route = {
  [@bs.module "react-router-dom"] external route : ReasonReact.reactClass = "Route";
  let make =
      (
        ~exact=false,
        ~path: string,
        ~component: ('a => ReasonReact.reactElement),
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=route,
      ~props={
        "exact": Js.Boolean.to_js_boolean(exact),
        "path": path,
        "component": component
      },
      children
    );
};

module NavLink = {
  [@bs.module "react-router-dom"] external navLink : ReasonReact.reactClass = "NavLink";
  let make = (~_to: string, ~exact=false, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=navLink,
      ~props={"to": _to, "exact": Js.Boolean.to_js_boolean(exact)},
      children
    );
};

module BrowserRouter = {
  [@bs.module "react-router-dom"] external browserRouter : ReasonReact.reactClass =
    "BrowserRouter";
  let make = (children) =>
    ReasonReact.wrapJsForReason(~reactClass=browserRouter, ~props=Js.Obj.empty(), children);
};
