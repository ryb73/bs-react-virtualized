[@decco] type dimensions = { width: int, height: int, };

let make:
    (~className: string=?, array(dimensions => 'a)) =>
    ReasonReact.component(ReasonReact.stateless, ReasonReact.noRetainedProps,
        ReasonReact.actionless);
