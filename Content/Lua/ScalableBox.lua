print("wow!");
local ScalableBox={}

function ScalableBox:ReceiveBeginPlay()
    self.bCanEverTick = true
    self.Super:ReceiveBeginPlay()
    print("ScalableBox:ReceiveBeginPlay")
end

local MyClass = Class({},nil,ScalableBox)

function ScalableBox:ReceiveEndPlay()
    for key, value in pairs(MyClass) do
        print(key)
    end
    print(ScalableBox.__inner_impl)
    print("ScalableBox:ReceiveEndPlay")
    self.Super:ReceiveEndPlay()
end

function ScalableBox:Tick(DeltaTime)
    print("actor:Tick",self, DeltaTime)
    -- call actor function
    local pos = self:K2_GetActorLocation()
    -- can pass self as Actor*
    local dist = self:GetHorizontalDistanceTo(self)
    print("actor pos",pos,dist)
end

function ScalableBox:OnHit(HitComp, OtherActor, OtherComp, NormalImpulse, Hit)
    print("TargetBox Hit by: ", OtherActor)
    -- Example: Apply damage if hit by a specific actor
    if OtherActor:GetName() == "SomeBulletActor" then
        print("Hit by bullet!")
        self:Destroy()  -- Destroy the TargetBox
    end
end

-- function actor:ReceiveTick(dt)
-- end

return Class({}, nil, ScalableBox)
